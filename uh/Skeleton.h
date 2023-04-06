#pragma once
#include "Bone.h"
#include "TestSkeletonandAnimation.h"//DEBUG
#include <iostream>



class OBBSkeleton{
public:
	bool loadSkeleton(Bone skeleton);
	bool loadAnimation(Animation anime);
	void update(float dt, std::vector<Particle>& particles);
	void draw(sf::RenderWindow& window);
	void moveParticles(std::vector<Particle>& particles);

	//DEBUG but should change to another later
	bool checkIfPointIsInSkeleton(Particle particle);
private:
	std::map<uint16_t, Bone*> boneMap;
	Bone m_skeleton;
	Animation m_anime;
};