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
		if(currentTimeIndex > Times.size()){
			currentTimeIndex = 0;
			currentTime -= Times[Times.size() - 1];
		}
	}
	procent = (currentTime-Times[currentTimeIndex])/(Times[(currentTimeIndex + 1)% Times.size()] - Times[currentTimeIndex]);//should be around 0 - 1
}



Transformation Animation::getpositionDownLine(uint16_t boneID, std::map<uint16_t, Bone*> &boneMap){
	Transformation theReturn;
	if(boneMap[boneID]->parent == nullptr){
		//root bone
		theReturn.position = sf::Vector2f(0,0);
		theReturn.rotation = transformations[currentTimeIndex][boneID] - ((transformations[currentTimeIndex][boneID] - transformations[(currentTimeIndex + 1)% Times.size()][boneID]) * procent);
	}
	else{
		//get the return from parent
		theReturn = getpositionDownLine(boneMap[boneID]->parent->id, boneMap);
		//add our and return it
		sf::Vector2f lPos = theReturn.position - boneMap[boneID]->thisBone.getPosition();
		//TODO: check if rotation should be -or not!
		theReturn.position.x = lPos.x * cos(DToR(theReturn.rotation)) - lPos.y * sin(DToR(theReturn.rotation));
		theReturn.position.y = lPos.x * sin(DToR(theReturn.rotation)) + lPos.y * cos(DToR(theReturn.rotation));
		
		theReturn.rotation += transformations[currentTimeIndex][boneID] - ((transformations[currentTimeIndex][boneID] - transformations[(currentTimeIndex + 1) % Times.size()][boneID]) * procent);
	}
	return theReturn;
}

Transformation Animation::getTransformationInterpolation(uint16_t boneID, std::map<uint16_t, Bone*> &boneMap)
{
	return getpositionDownLine(boneID, boneMap);
}
