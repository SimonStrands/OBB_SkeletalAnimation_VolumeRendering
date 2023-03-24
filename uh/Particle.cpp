#include "Particle.h"

Particle::Particle(sf::Color color, sf::Vector2f pos)
{
	this->m_orginalPosition = pos;
	m_particle.setFillColor(color);
	m_particle.setRadius(3);
	m_particle.setPosition(pos);
}

void Particle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_particle);
}

void Particle::changePosition(sf::Vector2f pos)
{
	m_particle.setPosition(pos);
}

sf::Vector2f Particle::getPosition() const
{
	return m_particle.getPosition();
}

sf::Vector2f Particle::getOrginalPosition() const
{
	return m_orginalPosition;
}

void Particle::changeOriginalPosition(sf::Vector2f pos)
{
	m_orginalPosition = pos;
	m_particle.setPosition(pos);
}
