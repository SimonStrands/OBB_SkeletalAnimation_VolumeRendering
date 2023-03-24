#pragma once
#include "OBB.h"

struct Bone{
	Bone(){
	}
	OBB thisBone;
	Bone *parent;
	uint16_t id;//maybe uint8?
	std::vector<Bone> children;
	void draw(sf::RenderWindow& window);
};