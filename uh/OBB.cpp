#include "OBB.h"

OBB::OBB(sf::Vector2f position, sf::Vector2f size, float rotation)
{
    this->position = position;
    this->OrginalPosition = position;
    this->rotation = rotation;
    this->size = size;
    DEBUGSHAPE.setFillColor(sf::Color(255,0,0,100));
    this->DEBUGSHAPE.setOrigin(0.f, size.y / 2);//size.x/2, size.y/2);
}

void OBB::init(sf::Vector2f position, sf::Vector2f size, float rotation)
{
    this->position = position;
    this->OrginalPosition = position;
    this->rotation = rotation;
    this->size = size;
    this->DEBUGSHAPE.setOrigin(0.f, size.y / 2);// size.x / 2, size.y / 2);
    DEBUGSHAPE.setFillColor(sf::Color(255,0,0,100));
}

void OBB::move(sf::Vector2f dir)
{
    position += dir;
}

void OBB::setPos(sf::Vector2f pos)
{
    this->position = pos;
}

void OBB::rotate(float rot)
{
    rotation += rot;
}

void OBB::setRotation(float rot)
{
    this->rotation = rot;
}

bool OBB::pointInside(sf::Vector2f point)
{
    sf::Vector2f lPos = point - position;//TODO: change this to orginal position
    float nXPos = lPos.x * cos(rotation) - lPos.y * sin(rotation);
    float nYPos = lPos.x * sin(rotation) + lPos.y * cos(rotation);
    return abs(nXPos - size.x / 2) < size.x/2  && abs(nYPos) < size.y/2;
}

void OBB::setColor(sf::Color color)
{
    DEBUGSHAPE.setFillColor(color);
}

sf::Vector2f OBB::getPosition() const
{
    return this->OrginalPosition;
}

void OBB::updateDebug()
{
    DEBUGSHAPE.setPosition(position);
    DEBUGSHAPE.setSize(size);
    DEBUGSHAPE.setRotation(RToD(-rotation));
}

void OBB::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(DEBUGSHAPE);
}
