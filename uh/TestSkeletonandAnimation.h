#pragma once
#include "Bone.h"
#include "Animation.h"

const float xOffset = 100;

static Bone testSkeleton;
static void buildTestSkeleton(){
	testSkeleton.id = 0;
	testSkeleton.parent.init(sf::Vector2f(0 + xOffset,0 + xOffset), sf::Vector2f(50,10));
	testSkeleton.children.push_back(Bone());

	testSkeleton.children[0].id = 1;
	testSkeleton.children[0].parent.init(sf::Vector2f(40 + xOffset,0 + xOffset), sf::Vector2f(50,10));
	testSkeleton.children[0].children.push_back(Bone());

	testSkeleton.children[0].children[0].id = 2;
	testSkeleton.children[0].children[0].parent.init(sf::Vector2f(80 + xOffset,0 + xOffset), sf::Vector2f(50,10));
}

static Animation testAnimation;
static void buildTestAnimation()
{
	testAnimation.Times.push_back(0.f);
	testAnimation.Times.push_back(1.f);
	testAnimation.Times.push_back(2.f);
	testAnimation.Times.push_back(5.f);
	testAnimation.nrOfBones = 3;
	std::map<uint16_t, float> temp;

	temp[0] = 0;
	temp[1] = 0;
	temp[2] = 0;
	testAnimation.transformations.push_back(temp);

	temp[0] = 90;
	temp[1] = 0;
	temp[2] = 0;
	testAnimation.transformations.push_back(temp);

	temp[0] = 0;
	temp[1] = 0;
	temp[2] = 0;
	testAnimation.transformations.push_back(temp);

	temp[0] = 25;
	temp[1] = 25;
	temp[2] = 25;
	testAnimation.transformations.push_back(temp);
}