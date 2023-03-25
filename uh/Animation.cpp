#include "Animation.h"

Animation::Animation()
{
	currentTime = 0.f;
	currentTimeIndex = 0;
	nrOfBones = 0;
	procent = 0;
}

bool Animation::loadAnimation(int nrOfBones, std::vector<float> times, std::vector<std::map<uint16_t, float>> transformations)
{
	if (times.size() != transformations.size()) {
		std::cout << "Error: times array and transformation array are not the same size!" << std::endl;
		return false;
	}
	this->nrOfBones = nrOfBones;
	this->Times = times;
	this->transformations = transformations;
	return true;
}

void Animation::updateAnimation(float dt)
{
	if(Times.size() < 0){return;}

	currentTime += dt;
	if(currentTime > Times[currentTimeIndex]){
		currentTimeIndex +=1;
		if(currentTimeIndex > Times.size() - 1){
			currentTimeIndex = 1;
			currentTime -= Times[Times.size() - 1];
		}
	}
	procent = (currentTime - Times[currentTimeIndex - 1])/(Times[currentTimeIndex] - Times[currentTimeIndex - 1]);//should be around 0 - 1
}

Transformation Animation::getpositionDownLine(uint16_t boneID, std::map<uint16_t, Bone*> &boneMap){
	Transformation theReturn;
	if(boneMap[boneID]->parent == nullptr){
		//root bone
		theReturn.position = boneMap[boneID]->thisBone.getPosition();
		theReturn.rotation += transformations[currentTimeIndex - 1][boneID] - ((transformations[currentTimeIndex - 1][boneID] - transformations[currentTimeIndex][boneID]) * procent);
	}
	else{
		//get the return from parent
		theReturn = getpositionDownLine(boneMap[boneID]->parent->id, boneMap);

		//add our and return it
		sf::Vector2f diff = boneMap[boneID]->thisBone.getPosition() - boneMap[boneID]->parent->thisBone.getPosition();
		//TODO: check if rotation should be -or not!
		theReturn.position.x += diff.x * cos(-theReturn.rotation) - diff.y * sin(-theReturn.rotation);
		theReturn.position.y += diff.x * sin(-theReturn.rotation) + diff.y * cos(-theReturn.rotation);
		
		theReturn.rotation += transformations[currentTimeIndex - 1][boneID] - ((transformations[currentTimeIndex - 1][boneID] - transformations[currentTimeIndex][boneID]) * procent);
	}
	return theReturn;
}

Transformation Animation::getTransformationInterpolation(uint16_t boneID, std::map<uint16_t, Bone*> &boneMap)
{
	return getpositionDownLine(boneID, boneMap);
}
