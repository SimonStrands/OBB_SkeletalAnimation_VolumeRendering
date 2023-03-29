#pragma once
#include <iostream>
#include <vector>
#include <random>
#include "RandomGenerator.h"
#include "DeltaTime.h"

#include "Particle.h"
#include "Skeleton.h"
#include "TestSkeletonandAnimation.h"//DEBUG

class Game {
private:
	sf::RenderWindow win;
	bool done;
	std::vector<Particle> particles;
	OBBSkeleton skeleton;
	Particle point;
	OBB testOBB;
	float deltaTimeSpeed;
	bool renderSkeleton;
public:
	Game();
	virtual ~Game();
	bool Update(float dt);
	void Render();
	void HandleEvents();
};