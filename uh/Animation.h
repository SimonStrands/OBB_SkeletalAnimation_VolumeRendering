#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bone.h"

struct Transformation{
	sf::Vector2f position;
	float rotation;
	//scale not needed;
};

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
	Transformation getTransformationInterpolation(uint16_t boneID, std::map<uint16_t, Bone*>& boneMap);

private:
	Transformation getpositionDownLine(uint16_t boneID, std::map<uint16_t, Bone*>& boneMap);//const?
};