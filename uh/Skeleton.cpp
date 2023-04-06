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

void OBBSkeleton::update(float dt, std::vector<Particle>& particles)
{
    //updates the animation such as index, keyframe aso
    m_anime.updateAnimation(dt);
    
    //update the transform in the bone
    Transformation a;
    a.position = boneMap[0]->thisBone.getPosition();
    a.rotation = boneMap[0]->thisBone.getRotation();
    m_anime.updateTransformations(0, boneMap, a);
    
    
    moveParticles(particles);
    
    //actually updates the bones position and rotation
    m_anime.updateBoneAnimation(0, boneMap);
}

void OBBSkeleton::draw(sf::RenderWindow& window)
{
    m_skeleton.draw(window);
}

void OBBSkeleton::moveParticles(std::vector<Particle>& particles)
{
    //for(size_t i = 0; i < particles.size(); i++){
    //    particles[i].reset();
    //}
    m_anime.moveParticle(boneMap, particles);
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
