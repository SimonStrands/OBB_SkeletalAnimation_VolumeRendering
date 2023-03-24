#include "Skeleton.h"

bool OBBSkeleton::loadSkeleton(Bone skeleton)
{
    m_skeleton = skeleton;//DEBUG
    return true;
}

bool OBBSkeleton::loadAnimation(Animation anime)
{
    m_anime = anime;
    return true;
}

void OBBSkeleton::update(float dt)
{
    m_anime.updateAnimation(dt);
    //update animation of obb here
}

void OBBSkeleton::draw(sf::RenderWindow& window)
{
    m_skeleton.draw(window);
}
