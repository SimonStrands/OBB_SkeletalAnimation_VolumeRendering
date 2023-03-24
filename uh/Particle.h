#pragma once
#include <SFML/Graphics.hpp>

class Particle : public sf::Drawable {
public:
	Particle(sf::Color color, sf::Vector2f pos);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void changePosition(sf::Vector2f pos);
	sf::Vector2f getPosition() const;
	sf::Vector2f getOrginalPosition() const;
private:
	sf::Vector2f m_orginalPosition;
	sf::CircleShape m_particle;
};