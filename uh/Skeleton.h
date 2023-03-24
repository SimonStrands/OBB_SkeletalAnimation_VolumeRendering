#pragma once
#include "Bone.h"
#include "TestSkeletonandAnimation.h"//DEBUG
#include <iostream>



class OBBSkeleton{
public:
	bool loadSkeleton(Bone skeleton);
	bool loadAnimation(Animation anime);
	void update(float dt);
	void draw(sf::RenderWindow& window);
private:
	Bone m_skeleton;
	Animation m_anime;
};