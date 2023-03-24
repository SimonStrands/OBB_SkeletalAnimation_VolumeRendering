#pragma once
#include <SFML/Graphics.hpp>
#include "Particle.h"//DEBUG

class OBB : public sf::Drawable{
public:
	OBB(sf::Vector2f position = sf::Vector2f(0,0), sf::Vector2f size = sf::Vector2f(10,10), float rotation = 0);
	void init(sf::Vector2f position = sf::Vector2f(0,0), sf::Vector2f size = sf::Vector2f(10,10), float rotation = 0);
	void move(sf::Vector2f dir);
	void setPos(sf::Vector2f pos);
	void rotate(float rot);
	void setRotation(float rot);
	bool pointInside(sf::Vector2f point);

	//DEBUG
	void debugPoint(const Particle& tester, Particle& changer);
	sf::Vector2f getPosition() const;
	void updateDebug();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	float rotation;//check if this is in degrees or radians
	sf::Vector2f position;
	sf::Vector2f OrginalPosition;
	sf::Vector2f size;//X,Y
	sf::RectangleShape DEBUGSHAPE;
	
};