#pragma once
#include <SFML/Graphics.hpp>
#include "RadiansAndDegrees.h"
#include "Particle.h"


class OBB : public sf::Drawable{
public:
	OBB(sf::Vector2f position = sf::Vector2f(0,0), sf::Vector2f size = sf::Vector2f(10,10), float rotation = 0);
	void init(sf::Vector2f position = sf::Vector2f(0,0), sf::Vector2f size = sf::Vector2f(10,10), float rotation = 0);
	void move(sf::Vector2f dir);
	void setPos(sf::Vector2f pos);
	void rotate(float rot);
	void setRotation(float rot);
	bool pointInside(sf::Vector2f point);
	bool pointInsideOrginal(sf::Vector2f point);

	sf::Vector2f getPosition() const;
	float getOrginalRotation() const;
	float getRotation() const;
	
	//DEBUG
	void setColor(sf::Color color);
	void updateDebug();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	float otherRotation;
private:
	float m_rotation;//check if this is in degrees or radians
	
	float m_orginalRotation;
	sf::Vector2f m_position;
	sf::Vector2f m_orginalPosition;
	sf::Vector2f m_size;//X,Y
	sf::RectangleShape DEBUGSHAPE;
	sf::CircleShape DEBUGSHAPECircle;
	
};