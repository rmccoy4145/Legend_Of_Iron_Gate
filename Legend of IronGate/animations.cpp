//
//  animations.cpp
//  mygame
//
//  Created by Ryan Mccoy on 2/14/14.
//  Copyright (c) 2014 Ryan Mccoy. All rights reserved.
//

#include "animations.h"

void Animations::zombieAnimations(EnemyContainer& enContainer)
{
for (unsigned int a = 0; a < enContainer.EnemyVector.size(); a++)
{
    if (enContainer.EnemyVector[a]->mState == 0 && enContainer.EnemyVector[a]->isAlive == true && enContainer.EnemyVector[a]->mType == 0)
    {
        int frame(6);
        enContainer.EnemyVector[a]->mSprite.setTextureRect(sf::IntRect(frame * 56, 0 * 100, 56, 100));
        for (frame = 6; frame > 0; frame--)
        {
            if(frame == 0)
            {frame = 6;}
        }
    }
}
}
/*
for (ParticleIterator it = ParticleContainer.begin(); it !=  ParticleContainer.end(); it++)
{
    
    Entity::Object* Base = *it;
    
    Base->Update(Lvl);
    
    Entity::Particle* Particle = dynamic_cast<Entity::Particle*>(Base);
    
    Entity::Projectile* Projectile = dynamic_cast<Entity::Projectile*>(Base);
    
    if(Particle)
    {
        
        Particle->Update(Lvl);
        
    }
    
    if(Projectile)
    {
        
        Projectile->Update(Lvl);
        
    }
    
    
}
*/