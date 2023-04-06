#pragma once
#include <SFML/Graphics.hpp>

struct Transformation{
	sf::Vector2f position;
	float rotation;
	float lastRotation;
	//scale not needed;

	Transformation():
		position(0, 0),
		rotation(0)
	{}
};