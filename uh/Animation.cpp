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

float Animation::getTransformationInterpolation(uint16_t boneID)
{
	return transformations[currentTimeIndex][boneID] - ((transformations[currentTimeIndex][boneID] - transformations[(currentTimeIndex + 1)% Times.size()][boneID]) * procent);
}
