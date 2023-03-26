#pragma once
#include "Transformation.h"
#include <iostream>
#include "Bone.h"

class Animation{
public:
	int currentTimeIndex;
	float currentTime;
	float procent;

	std::vector<float> Times;
	int nrOfBones;
	std::vector<std::map<uint16_t, float>> transformations;

	Animation();
	bool loadAnimation(int nrOfBones, std::vector<float> times, std::vector<std::map<uint16_t, float>> transformations);
		
	void updateAnimation(float dt);
	void animateBones(uint16_t boneID, std::map<uint16_t, Bone*>& boneMap, Transformation parentTransform);
	sf::Vector2f moveParticle(uint16_t boneID, std::map<uint16_t, Bone*>& boneMap, sf::Vector2f particlePosition);
private:
	
};