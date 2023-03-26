#pragma once
#include "OBB.h"
#include "Transformation.h"

struct Bone{
	Bone(){
	}
	OBB thisBone;
	Bone *parent;
	uint16_t id;//maybe uint8?
	std::vector<Bone> children;
	Transformation trans;

	void draw(sf::RenderWindow& window);
};