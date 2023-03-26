#pragma once
#include "Bone.h"
#include "Animation.h"

const float xOffset = 200;
const float yOffset = 300;

static Bone testSkeleton;
static void buildTestSkeleton(){
	testSkeleton.id = 0;
	testSkeleton.parent = nullptr;
	testSkeleton.thisBone.init(sf::Vector2f(0 + xOffset,0 + yOffset), sf::Vector2f(70,50));
	testSkeleton.children.push_back(Bone());
	testSkeleton.thisBone.setColor(sf::Color(255, 0, 0, 200));

	testSkeleton.children[0].id = 1;
	testSkeleton.children[0].parent = &testSkeleton;
	testSkeleton.children[0].thisBone.init(sf::Vector2f(60 + xOffset,0 + yOffset), sf::Vector2f(70,50));
	testSkeleton.children[0].thisBone.setColor(sf::Color(0, 255, 0, 200));
	testSkeleton.children[0].children.push_back(Bone());

	testSkeleton.children[0].children[0].id = 2;
	testSkeleton.children[0].children[0].parent = &testSkeleton.children[0];
	testSkeleton.children[0].children[0].thisBone.init(sf::Vector2f(120 + xOffset,0 + yOffset), sf::Vector2f(70,50));
	testSkeleton.children[0].thisBone.setColor(sf::Color(0, 0, 255, 200));
	testSkeleton.children[0].children[0].children.push_back(Bone());

	testSkeleton.children[0].children[0].children[0].id = 3;
	testSkeleton.children[0].children[0].children[0].parent = &testSkeleton.children[0].children[0];
	testSkeleton.children[0].children[0].children[0].thisBone.init(sf::Vector2f(180 + xOffset,0 + yOffset), sf::Vector2f(70,50));
	testSkeleton.children[0].children[0].children[0].thisBone.setColor(sf::Color(0, 255, 255, 200));

}

static Animation testAnimation;
static void buildTestAnimation()
{
	testAnimation.Times.push_back(0.f);
	testAnimation.Times.push_back(1.f);
	testAnimation.Times.push_back(2.f);
	testAnimation.Times.push_back(4.f);
	testAnimation.Times.push_back(6.f);
	testAnimation.nrOfBones = 3;
	std::map<uint16_t, float> temp;

	temp[0] = 0;
	temp[1] = 0;
	temp[2] = 0;
	//temp[3] = 0;
	testAnimation.transformations.push_back(temp);

	temp[0] = DToR(90);
	temp[1] = 0;
	temp[2] = 0;
	//temp[3] = 0;
	testAnimation.transformations.push_back(temp);

	temp[0] = 0;
	temp[1] = 0;
	temp[2] = 0;
	//temp[3] = 0;
	testAnimation.transformations.push_back(temp);

	temp[0] = DToR(25);
	temp[1] = DToR(25);
	temp[2] = DToR(25);
	//temp[3] = 0;
	testAnimation.transformations.push_back(temp);

	temp[0] = 0;
	temp[1] = 0;
	temp[2] = 0;
	//temp[3] = 0;
	testAnimation.transformations.push_back(temp);
}