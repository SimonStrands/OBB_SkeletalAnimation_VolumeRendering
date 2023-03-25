#include "Skeleton.h"

void addBonesToMap(std::map<uint16_t, Bone*>& boneMap, Bone &bone){
     boneMap.insert(std::pair<uint16_t, Bone*>(bone.id, &bone));
     for(int i = 0; i < bone.children.size(); i++){
         addBonesToMap(boneMap, bone.children[i]);
     }
}

bool OBBSkeleton::loadSkeleton(Bone skeleton)
{
    m_skeleton = skeleton;//DEBUG
    addBonesToMap(boneMap, m_skeleton);

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
    //Maybe can do a normal for loop here based on animation nrOfBones
    std::map<uint16_t, Bone*>::iterator it;
    for (it = boneMap.begin(); it != boneMap.end(); it++)
    {
        //very badly made but works for now (now goes trought every parent for every child (O^2))
        Transformation temp = m_anime.getTransformationInterpolation(it->first, boneMap);
        boneMap[it->first]->thisBone.setPos(temp.position);
        boneMap[it->first]->thisBone.setRotation(temp.rotation);
    }
}

void OBBSkeleton::draw(sf::RenderWindow& window)
{
    m_skeleton.draw(window);
}

bool OBBSkeleton::checkIfPointIsInSkeleton(Particle particle)
{
    std::map<uint16_t, Bone*>::iterator it;
    for (it = boneMap.begin(); it != boneMap.end(); it++)
    {
        if(it->second->thisBone.pointInside(particle.getPosition())){
            std::cout << "a particle inside skeleton" << std::endl;
        }
    }
    return false;
}
