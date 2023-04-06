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
	//testSkeleton.children[0].children.push_back(Bone());
	//
	//testSkeleton.children[0].children[0].id = 2;
	//testSkeleton.children[0].children[0].parent = &testSkeleton.children[0];
	//testSkeleton.children[0].children[0].thisBone.init(sf::Vector2f(120 + xOffset,0 + yOffset), sf::Vector2f(70,50));
	//testSkeleton.children[0].thisBone.setColor(sf::Color(0, 0, 255, 200));
	//testSkeleton.children[0].children[0].children.push_back(Bone());
	//
	//testSkeleton.children[0].children[0].children[0].id = 3;
	//testSkeleton.children[0].children[0].children[0].parent = &testSkeleton.children[0].children[0];
	//testSkeleton.children[0].children[0].children[0].thisBone.init(sf::Vector2f(180 + xOffset,0 + yOffset), sf::Vector2f(70,50));
	//testSkeleton.children[0].children[0].children[0].thisBone.setColor(sf::Color(0, 255, 255, 200));

}

static Animation testAnimation;
static void buildTestAnimation()
{
	testAnimation.Times.push_back(0.f);
	testAnimation.Times.push_back(0.5f);
	testAnimation.Times.push_back(1.f);
	testAnimation.Times.push_back(2.f);
	testAnimation.Times.push_back(4.f);
	testAnimation.Times.push_back(5.f);
	testAnimation.nrOfBones = 3;
	std::map<uint16_t, float> temp;

	temp[0] = 0;
	temp[1] = 0;
	//temp[2] = 0;
	//temp[3] = 0;
	testAnimation.transformations.push_back(temp);

	temp[0] = DToR(90);
	temp[1] = 0;
	//temp[2] = 0;
	//temp[3] = 0;
	testAnimation.transformations.push_back(temp);

	temp[0] = 0;
	temp[1] = 0;
	//temp[2] = 0;
	//temp[3] = 0;
	testAnimation.transformations.push_back(temp);

	temp[0] = DToR(35);
	temp[1] = DToR(35);
	//temp[2] = DToR(35);
	//temp[3] = DToR(35);
	testAnimation.transformations.push_back(temp);

	temp[0] = DToR(-35);
	temp[1] = DToR(-35);
	//temp[2] = DToR(-35);
	//temp[3] = DToR(-35);
	testAnimation.transformations.push_back(temp);

	temp[0] = 0;
	temp[1] = 0;
	//temp[2] = 0;
	//temp[3] = 0;
	testAnimation.transformations.push_back(temp);
}

/*
#pragma once
#include "Bone.h"
#include "Animation.h"

const float xOffset = 400;
const float yOffset = 300;

static Bone testSkeleton;
static void buildTestSkeleton(){
	int id = 0;
	//BODY
	testSkeleton.id = id++;
	testSkeleton.parent = nullptr;
	//testSkeleton.thisBone.init(sf::Vector2f(-40 + xOffset, -40 + yOffset), sf::Vector2f(90,60), DToR(-90));
	testSkeleton.thisBone.init(sf::Vector2f(-40 + xOffset, -40 + yOffset), sf::Vector2f(90,60), DToR(0));
	testSkeleton.children.push_back(Bone());//RIGHT ARM
	testSkeleton.children.push_back(Bone());//LEFT ARM
	testSkeleton.children.push_back(Bone());//HEAD
	testSkeleton.children.push_back(Bone());//RIGHT LEG
	testSkeleton.children.push_back(Bone());//LEFT LEG
	testSkeleton.thisBone.setColor(sf::Color(0, 0, 100, 200));

	//RIGHT ARM
	testSkeleton.children[0].id = id++;
	testSkeleton.children[0].parent = &testSkeleton;
	//testSkeleton.children[0].thisBone.init(sf::Vector2f(-10 + xOffset, -65 + yOffset), sf::Vector2f(70,20), DToR(90));
	testSkeleton.children[0].thisBone.init(sf::Vector2f(-10 + xOffset, -65 + yOffset), sf::Vector2f(70,20), DToR(0));
	testSkeleton.children[0].thisBone.setColor(sf::Color(0, 0, 200, 200));
	testSkeleton.children[0].children.push_back(Bone());

	testSkeleton.children[0].children[0].id = id++;
	testSkeleton.children[0].children[0].parent = &testSkeleton.children[0];
	testSkeleton.children[0].children[0].thisBone.init(sf::Vector2f(50 + xOffset, -65 + yOffset), sf::Vector2f(70,20), DToR(0));
	testSkeleton.children[0].children[0].thisBone.setColor(sf::Color(0, 0, 255, 200));

	//LEFT ARM
	testSkeleton.children[1].id = id++;
	testSkeleton.children[1].parent = &testSkeleton;
	//testSkeleton.children[1].thisBone.init(sf::Vector2f(-10 + xOffset, -15 + yOffset), sf::Vector2f(70,20), DToR(-90));
	testSkeleton.children[1].thisBone.init(sf::Vector2f(-10 + xOffset, -15 + yOffset), sf::Vector2f(70,20), DToR(0));
	testSkeleton.children[1].thisBone.setColor(sf::Color(0, 100, 0, 200));
	testSkeleton.children[1].children.push_back(Bone());

	testSkeleton.children[1].children[0].id = id++;
	testSkeleton.children[1].children[0].parent = &testSkeleton.children[1];
	testSkeleton.children[1].children[0].thisBone.init(sf::Vector2f(50 + xOffset, -15 + yOffset), sf::Vector2f(70,20), DToR(0));
	testSkeleton.children[1].children[0].thisBone.setColor(sf::Color(0, 200, 0, 200));

	//HEAD
	testSkeleton.children[2].id = id++;
	testSkeleton.children[2].parent = &testSkeleton;
	//testSkeleton.children[2].thisBone.init(sf::Vector2f(-30 + xOffset, -40 + yOffset), sf::Vector2f(70,50), DToR(180));
	testSkeleton.children[2].thisBone.init(sf::Vector2f(-30 + xOffset, -40 + yOffset), sf::Vector2f(70,50), DToR(0));
	testSkeleton.children[2].thisBone.setColor(sf::Color(0, 255, 0, 200));

	//RIGHT LEG
	testSkeleton.children[3].id = id++;
	testSkeleton.children[3].parent = &testSkeleton;
	testSkeleton.children[3].thisBone.init(sf::Vector2f(40 + xOffset, -60 + yOffset), sf::Vector2f(70,15), DToR(0));
	testSkeleton.children[3].thisBone.setColor(sf::Color(255, 0, 255, 200));
	testSkeleton.children[3].children.push_back(Bone());

	testSkeleton.children[3].children[0].id = id++;
	testSkeleton.children[3].children[0].parent = &testSkeleton.children[3];
	testSkeleton.children[3].children[0].thisBone.init(sf::Vector2f(100 + xOffset, -60 + yOffset), sf::Vector2f(70,15), DToR(0));
	testSkeleton.children[3].children[0].thisBone.setColor(sf::Color(255, 0, 255, 200));

	//LEFT LEG
	testSkeleton.children[4].id = id++;
	testSkeleton.children[4].parent = &testSkeleton;
	testSkeleton.children[4].thisBone.init(sf::Vector2f(40 + xOffset, -20 + yOffset), sf::Vector2f(70,15), DToR(0));
	testSkeleton.children[4].thisBone.setColor(sf::Color(255, 0, 255, 200));
	testSkeleton.children[4].children.push_back(Bone());

	testSkeleton.children[4].children[0].id = id++;
	testSkeleton.children[4].children[0].parent = &testSkeleton.children[4];
	testSkeleton.children[4].children[0].thisBone.init(sf::Vector2f(100 + xOffset, -20 + yOffset), sf::Vector2f(70,15), DToR(0));
	testSkeleton.children[4].children[0].thisBone.setColor(sf::Color(255, 255, 255, 200));

}

static Animation testAnimation;
static void buildTestAnimation()
{
	testAnimation.Times.push_back(0.f);
	testAnimation.Times.push_back(1.f);
	testAnimation.Times.push_back(2.f);
	testAnimation.Times.push_back(3.f);
	testAnimation.Times.push_back(4.f);
	testAnimation.Times.push_back(5.f);
	testAnimation.Times.push_back(6.f);
	testAnimation.Times.push_back(7.f);
	testAnimation.Times.push_back(8.f);
	testAnimation.nrOfBones = 10;
	std::map<uint16_t, float> temp;

	//T-POSE
	temp[0] = DToR(0);  //BODY
	temp[1] = DToR(0);   //RIGHT ARM 1
	temp[2] = DToR(0);    //RIGHT ARM 2
	temp[3] = DToR(0);  //LEFT ARM 1
	temp[4] = DToR(0);    //LEFT ARM 2
	temp[5] = DToR(0);  //HEAD
	temp[6] = DToR(0);    //RIGHT LEG 1
	temp[7] = DToR(0);    //RIGHT LEG 2
	temp[8] = DToR(0);    //LEFT LEG 1
	temp[9] = DToR(0);    //LEFT LEG 2
	testAnimation.transformations.push_back(temp);
	//T-POSE
	temp[0] = DToR(-90);  //BODY
	temp[1] = DToR(90);   //RIGHT ARM 1
	temp[2] = DToR(0);    //RIGHT ARM 2
	temp[3] = DToR(-90);  //LEFT ARM 1
	temp[4] = DToR(0);    //LEFT ARM 2
	temp[5] = DToR(180);  //HEAD
	temp[6] = DToR(0);    //RIGHT LEG 1
	temp[7] = DToR(0);    //RIGHT LEG 2
	temp[8] = DToR(0);    //LEFT LEG 1
	temp[9] = DToR(0);    //LEFT LEG 2
	testAnimation.transformations.push_back(temp);

	//
	temp[0] = DToR(-90);  //BODY
	temp[1] = DToR(135);   //RIGHT ARM 1
	temp[2] = DToR(45);    //RIGHT ARM 2
	temp[3] = DToR(-10);  //LEFT ARM 1
	temp[4] = DToR(0);    //LEFT ARM 2
	temp[5] = DToR(180);  //HEAD
	temp[6] = DToR(0);    //RIGHT LEG 1
	temp[7] = DToR(0);    //RIGHT LEG 2
	temp[8] = DToR(0);    //LEFT LEG 1
	temp[9] = DToR(0);    //LEFT LEG 2    
	testAnimation.transformations.push_back(temp);

	temp[0] = DToR(-90);  //BODY
	temp[1] = DToR(135);   //RIGHT ARM 1
	temp[2] = DToR(0);    //RIGHT ARM 2
	temp[3] = DToR(-10);  //LEFT ARM 1
	temp[4] = DToR(0);    //LEFT ARM 2
	temp[5] = DToR(180);  //HEAD
	temp[6] = DToR(0);    //RIGHT LEG 1
	temp[7] = DToR(0);    //RIGHT LEG 2
	temp[8] = DToR(0);    //LEFT LEG 1
	temp[9] = DToR(0);    //LEFT LEG 2     
	testAnimation.transformations.push_back(temp);

	temp[0] = DToR(-90);  //BODY
	temp[1] = DToR(135);   //RIGHT ARM 1
	temp[2] = DToR(45);    //RIGHT ARM 2
	temp[3] = DToR(-10);  //LEFT ARM 1
	temp[4] = DToR(0);    //LEFT ARM 2
	temp[5] = DToR(180);  //HEAD
	temp[6] = DToR(0);    //RIGHT LEG 1
	temp[7] = DToR(0);    //RIGHT LEG 2
	temp[8] = DToR(0);    //LEFT LEG 1
	temp[9] = DToR(0);    //LEFT LEG 2    
	testAnimation.transformations.push_back(temp);

	temp[0] = DToR(-90);  //BODY
	temp[1] = DToR(20);   //RIGHT ARM 1
	temp[2] = DToR(-10);  //RIGHT ARM 2
	temp[3] = DToR(-20);  //LEFT ARM 1
	temp[4] = DToR(10);    //LEFT ARM 2
	temp[5] = DToR(180);  //HEAD
	temp[6] = DToR(0);    //RIGHT LEG 1
	temp[7] = DToR(0);    //RIGHT LEG 2
	temp[8] = DToR(0);    //LEFT LEG 1
	temp[9] = DToR(0);    //LEFT LEG 2    
	testAnimation.transformations.push_back(temp);

	temp[0] = DToR(-90);  //BODY
	temp[1] = DToR(20);   //RIGHT ARM 1
	temp[2] = DToR(-10);  //RIGHT ARM 2
	temp[3] = DToR(-20);  //LEFT ARM 1
	temp[4] = DToR(10);    //LEFT ARM 2
	temp[5] = DToR(180);  //HEAD
	temp[6] = DToR(0);    //RIGHT LEG 1
	temp[7] = DToR(0);    //RIGHT LEG 2
	temp[8] = DToR(0);    //LEFT LEG 1
	temp[9] = DToR(0);    //LEFT LEG 2    
	testAnimation.transformations.push_back(temp);

	temp[0] = DToR(-90);  //BODY
	temp[1] = DToR(20);   //RIGHT ARM 1
	temp[2] = DToR(-10);  //RIGHT ARM 2
	temp[3] = DToR(-20);  //LEFT ARM 1
	temp[4] = DToR(10);    //LEFT ARM 2
	temp[5] = DToR(180);  //HEAD
	temp[6] = DToR(0);    //RIGHT LEG 1
	temp[7] = DToR(0);    //RIGHT LEG 2
	temp[8] = DToR(0);    //LEFT LEG 1
	temp[9] = DToR(0);    //LEFT LEG 2    
	testAnimation.transformations.push_back(temp);

	temp[0] = DToR(-90);  //BODY
	temp[1] = DToR(20);   //RIGHT ARM 1
	temp[2] = DToR(-10);  //RIGHT ARM 2
	temp[3] = DToR(-20);  //LEFT ARM 1
	temp[4] = DToR(10);    //LEFT ARM 2
	temp[5] = DToR(180);  //HEAD
	temp[6] = DToR(20);    //RIGHT LEG 1
	temp[7] = DToR(40);    //RIGHT LEG 2
	temp[8] = DToR(-20);    //LEFT LEG 1
	temp[9] = DToR(-40);    //LEFT LEG 2    
	testAnimation.transformations.push_back(temp);

	//BACK TO T-POSE
	temp[0] = DToR(-90);  //BODY
	temp[1] = DToR(90);   //RIGHT ARM 1
	temp[2] = DToR(0);    //RIGHT ARM 2
	temp[3] = DToR(-90);  //LEFT ARM 1
	temp[4] = DToR(0);    //LEFT ARM 2
	temp[5] = DToR(180);  //HEAD
	temp[6] = DToR(0);    //RIGHT LEG 1
	temp[7] = DToR(0);    //RIGHT LEG 2
	temp[8] = DToR(0);    //LEFT LEG 1
	temp[9] = DToR(0);    //LEFT LEG 2
	testAnimation.transformations.push_back(temp);
}
*/