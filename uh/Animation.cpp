#include "Animation.h"

Animation::Animation()
{
	currentTime = 0.f;
	currentTimeIndex = 1;
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
	if(Times.size() < 1){return;}

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

void Animation::updateTransformations(uint16_t boneID, std::map<uint16_t, Bone*>& boneMap, Transformation parentTransform)
{
	if(transformations.size() < 2){return;}

	Transformation trans;
	trans.lastRotation = boneMap[boneID]->trans.rotation;
	if(boneMap[boneID]->parent == nullptr){
		//root bone
		 trans.position = parentTransform.position;
		 trans.rotation = transformations[currentTimeIndex - 1][boneID] - ((transformations[currentTimeIndex - 1][boneID] - transformations[currentTimeIndex][boneID]) * procent);
	}
	else{
		sf::Vector2f diff = boneMap[boneID]->thisBone.getPosition() - boneMap[boneID]->parent->thisBone.getPosition();
		//TODO: check if rotation should be -or not!
		trans.position.x = parentTransform.position.x + (diff.x * cos(-parentTransform.rotation) - diff.y * sin(-parentTransform.rotation));
		trans.position.y = parentTransform.position.y + (diff.x * sin(-parentTransform.rotation) + diff.y * cos(-parentTransform.rotation));
		
		trans.rotation += parentTransform.rotation + (transformations[currentTimeIndex - 1][boneID] - ((transformations[currentTimeIndex - 1][boneID] - transformations[currentTimeIndex][boneID]) * procent));
	}
	
	//this can be changed later
	boneMap[boneID]->trans = trans;
	
	for(int i = 0; i < boneMap[boneID]->children.size(); i++){
		updateTransformations(boneMap[boneID]->children[i].id, boneMap, trans);
	}
}

void Animation::updateBoneAnimation(uint16_t boneID, std::map<uint16_t, Bone*>& boneMap)
{
	boneMap[boneID]->thisBone.setPos(boneMap[boneID]->trans.position);
	boneMap[boneID]->thisBone.setRotation(boneMap[boneID]->trans.rotation);
	for(int i = 0; i < boneMap[boneID]->children.size(); i++){
		updateBoneAnimation(boneMap[boneID]->children[i].id, boneMap);
	}
}

void Animation::moveParticle(std::map<uint16_t, Bone*>& boneMap, std::vector<Particle>& particles)
{
	for (auto const& [key, val] : boneMap)
	{
		for(size_t i = 0; i < particles.size(); i++){
			if(val->thisBone.pointInside(particles[i].getPosition())){

				sf::Vector2f diff = particles[i].getPosition() - val->trans.position;
				//sf::Vector2f diff = particles[i].getPosition() - boneMap[0]->thisBone.getPosition();
				sf::Vector2f newPos(0,0);
				float rotation = -(val->trans.rotation - val->trans.lastRotation);

				newPos.x = val->trans.position.x + (diff.x * cos(rotation) - diff.y * sin(rotation));
				newPos.y = val->trans.position.y + (diff.x * sin(rotation) + diff.y * cos(rotation));
				particles[i].changePosition(newPos);
			}
		}
	}
}
