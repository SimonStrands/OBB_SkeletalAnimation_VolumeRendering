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

void Animation::animateBones(uint16_t boneID, std::map<uint16_t, Bone*>& boneMap, Transformation parentTransform)
{
	Transformation trans;
	if(boneMap[boneID]->parent == nullptr){
		//root bone
		 boneMap[boneID]->thisBone.setRotation(transformations[currentTimeIndex - 1][boneID] - ((transformations[currentTimeIndex - 1][boneID] - transformations[currentTimeIndex][boneID]) * procent));
		 trans.position = parentTransform.position;
		 trans.rotation = boneMap[boneID]->thisBone.getRotation();
	}
	else{
		sf::Vector2f diff = boneMap[boneID]->thisBone.getPosition() - boneMap[boneID]->parent->thisBone.getPosition();
		//TODO: check if rotation should be -or not!
		trans.position.x = parentTransform.position.x + (diff.x * cos(-parentTransform.rotation) - diff.y * sin(-parentTransform.rotation));
		trans.position.y = parentTransform.position.y + (diff.x * sin(-parentTransform.rotation) + diff.y * cos(-parentTransform.rotation));
		
		trans.rotation += parentTransform.rotation + (transformations[currentTimeIndex - 1][boneID] - ((transformations[currentTimeIndex - 1][boneID] - transformations[currentTimeIndex][boneID]) * procent));
	}
	
	//this can be changed later
	boneMap[boneID]->thisBone.setRotation(trans.rotation);
	boneMap[boneID]->thisBone.setPos(trans.position);
	boneMap[boneID]->trans = trans;
	
	for(int i = 0; i < boneMap[boneID]->children.size(); i++){
		animateBones(boneMap[boneID]->children[i].id, boneMap, trans);
	}
}

void Animation::moveParticle(std::map<uint16_t, Bone*>& boneMap, std::vector<Particle>& particles)
{
	
}
