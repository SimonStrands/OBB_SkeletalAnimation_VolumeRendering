#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

struct Animation{
	int currentTimeIndex;
	float currentTime;
	float procent;

	std::vector<float> Times;
	int nrOfBones;
	std::vector<std::map<uint16_t, float>> transformations;

	Animation();
	bool loadAnimation(int nrOfBones, std::vector<float> times, std::vector<std::map<uint16_t, float>> transformations);
		
	void updateAnimation(float dt);
	float getTransformationInterpolation(uint16_t boneID);
};