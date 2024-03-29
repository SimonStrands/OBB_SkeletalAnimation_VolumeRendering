#pragma once
#include <SFML/Graphics.hpp>

class Particle : public sf::Drawable {
public:
	Particle(sf::Color color, sf::Vector2f pos);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void changePosition(sf::Vector2f pos);
	void reset();
	sf::Vector2f getPosition() const;
	sf::Vector2f getOrginalPosition() const;
	//DEBUG
	void changeOriginalPosition(sf::Vector2f pos);
private:
	sf::Vector2f m_orginalPosition;
	sf::CircleShape m_particle;
};