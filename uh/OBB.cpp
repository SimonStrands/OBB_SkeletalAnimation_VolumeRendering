#include "OBB.h"

OBB::OBB(sf::Vector2f position, sf::Vector2f size, float rotation)
{
    this->m_position = position;
    this->m_orginalPosition = position;
    this->m_rotation = rotation;
    this->m_orginalRotation = rotation;
    this->m_size = size;
    DEBUGSHAPE.setFillColor(sf::Color(255,0,0,100));
    this->DEBUGSHAPE.setOrigin(0.f, size.y / 2);//size.x/2, size.y/2);
    DEBUGSHAPECircle.setFillColor(sf::Color::White);
    DEBUGSHAPECircle.setRadius(2.f);
    DEBUGSHAPECircle.setOrigin(2,2);
}

void OBB::init(sf::Vector2f position, sf::Vector2f size, float rotation)
{
    this->m_position = position;
    this->m_orginalPosition = position;
    this->m_orginalRotation = rotation;
    this->m_rotation = rotation;
    this->m_size = size;
    this->DEBUGSHAPE.setOrigin(0.f, size.y / 2);// size.x / 2, size.y / 2);
    DEBUGSHAPE.setFillColor(sf::Color(255,0,0,100));
    DEBUGSHAPECircle.setFillColor(sf::Color::White);
    DEBUGSHAPECircle.setRadius(2.f);
    DEBUGSHAPECircle.setOrigin(2,2);
}

void OBB::move(sf::Vector2f dir)
{
    m_position += dir;
}

void OBB::setPos(sf::Vector2f pos)
{
    this->m_position = pos;
}

void OBB::rotate(float rot)
{
    m_rotation += rot;
}

void OBB::setRotation(float rot)
{
    this->m_rotation = rot;
}

bool OBB::pointInside(sf::Vector2f point)
{
    sf::Vector2f lPos = point - m_position;
    float nXPos = lPos.x * cos(m_rotation) - lPos.y * sin(m_rotation);
    float nYPos = lPos.x * sin(m_rotation) + lPos.y * cos(m_rotation);
    return abs(nXPos - m_size.x / 2) < m_size.x/2  && abs(nYPos) < m_size.y/2;
}

bool OBB::pointInsideOrginal(sf::Vector2f point)
{
    sf::Vector2f lPos = point - m_orginalPosition;
    float nXPos = lPos.x * cos(m_orginalRotation) - lPos.y * sin(m_orginalRotation);
    float nYPos = lPos.x * sin(m_orginalRotation) + lPos.y * cos(m_orginalRotation);
    return abs(nXPos - m_size.x / 2) < m_size.x/2  && abs(nYPos) < m_size.y/2;
}

void OBB::setColor(sf::Color color)
{
    DEBUGSHAPE.setFillColor(color);
}

sf::Vector2f OBB::getPosition() const
{
    return this->m_orginalPosition;
}

float OBB::getOrginalRotation() const
{
    return m_orginalRotation;
}

float OBB::getRotation() const
{
    return m_rotation;
}

void OBB::updateDebug()
{
    DEBUGSHAPE.setPosition(m_position);
    DEBUGSHAPECircle.setPosition(DEBUGSHAPE.getPosition());
    DEBUGSHAPECircle.setRadius(2.f);
    DEBUGSHAPE.setSize(m_size);
    DEBUGSHAPE.setRotation(RToD(-m_rotation));
}

void OBB::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(DEBUGSHAPE);
    target.draw(DEBUGSHAPECircle);
}
