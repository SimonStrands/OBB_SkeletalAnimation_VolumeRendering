#include "OBB.h"

OBB::OBB(sf::Vector2f position, sf::Vector2f size, float rotation)
{
    this->position = position;
    this->OrginalPosition = position;
    this->rotation = rotation;
    this->size = size;
    this->DEBUGSHAPE.setOrigin(size.x/2, size.y/2);
}

void OBB::init(sf::Vector2f position, sf::Vector2f size, float rotation)
{
    this->position = position;
    this->OrginalPosition = position;
    this->rotation = rotation;
    this->size = size;
    this->DEBUGSHAPE.setOrigin(size.x/2, size.y/2);
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
    float nXPos = lPos.x * cos(DToR(rotation)) - lPos.y * sin(DToR(rotation));
    float nYPos = lPos.x * sin(DToR(rotation)) + lPos.y * cos(DToR(rotation));
    return abs(nXPos) < size.x/2 && abs(nYPos) < size.y/2;
}

void OBB::debugPoint(const Particle& tester, Particle& changer)
{
    sf::Vector2f lPos = tester.getOrginalPosition() - position;
    float nXPos = lPos.x * cos(DToR(rotation)) - lPos.y * sin(DToR(rotation));
    float nYPos = lPos.x * sin(DToR(rotation)) + lPos.y * cos(DToR(rotation));
    changer.changePosition(sf::Vector2f(nXPos, nYPos) + position);
}

sf::Vector2f OBB::getPosition() const
{
    return this->OrginalPosition;
}

void OBB::updateDebug()
{
    DEBUGSHAPE.setFillColor(sf::Color(255,0,0,100));
    DEBUGSHAPE.setPosition(position);
    DEBUGSHAPE.setSize(size);
    DEBUGSHAPE.setRotation(-rotation);
}

void OBB::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(DEBUGSHAPE);
}
