//
//  update.cpp
//  mygame
//
//  Created by Ryan Mccoy on 2/6/14.
//  Copyright (c) 2014 Ryan Mccoy. All rights reserved.
//

#include "update.h"

void Update::AddObjects(LevelContainer& lContainer, EntityContainer& eContainer, EnemyContainer& enContainer, Player& player, Textures& textures, Sounds& sound)
{
    //ADDING OBJECTS----------------------------------------------------------------------------------
    //for (iter it = eContainer.SpriteVector.begin(); it < eContainer.SpriteVector.end(); it++)
    for (unsigned int i = 0; i < eContainer.SpriteVector.size(); i++)
    {
        if (eContainer.SpriteVector[i]->isAlive == false && (eContainer.SpriteVector[i]->mType == 0 && (eContainer.SpriteVector[i]->mState == 1)))
        {
            
            for (int c = 0; c < 100; c++)
            {
                sf::Vector2f fposition = (eContainer.SpriteVector[i]->GetPosition());
                std::unique_ptr<Entity> eParticle(new ExplosionParticle(fposition, *textures.particle1, *textures.particle));
                eContainer.SpriteVector.push_back(std::move(eParticle));
                
            }
            eContainer.SpriteVector[i]->mState = 2;
        }
    }
    if (player.mAction == 1)
    {
        std::unique_ptr<Entity> Sprite(new Fireball(player.GetPosition(), *textures.fireball, *sound.mPistolBuff));
        Sprite->mSprite.setPosition(player.GetPosition());
        if (player.ReturnSpriteDirection() == false)
        {
            Sprite->mDirection = 0;
        }
        else
        {
            Sprite->mDirection = 1;
        }
        Sprite->mSound.play();
        eContainer.SpriteVector.push_back(std::move(Sprite));
        player.mAction = 0;
        
    }
}

void Update::RemoveObjects(LevelContainer& lContainer, EntityContainer& eContainer, EnemyContainer& enContainer, Player& player, Textures& textures)
{
    //DELETING OBJECTS---------------------------------------------------------------------------------
    
    //DELETING EXPLOSION PARTICLES
    for (iter it = eContainer.SpriteVector.begin(); it < eContainer.SpriteVector.end(); it++)
    {
        if ((*it)->isAlive == false && (*it)->mState == 2)
        {
            
            auto todestroyBegin = std::remove_if (eContainer.SpriteVector.begin(), eContainer.SpriteVector.end(), std::mem_fn(&Entity::isDestroyed));
            eContainer.SpriteVector.erase(todestroyBegin, eContainer.SpriteVector.end());
            
        }
    }
}

void Update::Updates(LevelContainer& lContainer, EntityContainer& eContainer, EnemyContainer& enContainer, Player& player, Textures& textures)
{
    

    //ALL UPDATES----------------ALL UPDATES--------------ALL UPDATES---------ALL UPDATES---------------
    //PLAYER UPDATES-------------------------------------------------------------------------------------
    
    player.ReturnSprite().move(0,3);
    
    //ENEMY UPDATES--------------------------------------------------------------------------------------
    
    for (enemyiter it = enContainer.EnemyVector.begin(); it < enContainer.EnemyVector.end(); it++)
    {
     
            
       (*it)->Animations(player);
        
        ////////////////GRAVITY
        (*it)->mSprite.move(0, 3);
        
        ////////////////LevelCollision
        for (unsigned int b = 0; b < lContainer.LevelVector.size(); b++)
        {
        if (((*it)->mSprite.getGlobalBounds().top + (*it)->mSprite.getGlobalBounds().height) >= lContainer.LevelVector[b].mSprite.getGlobalBounds().top)
        {
          (*it)->mSprite.move(0, -3);
        }
        }
        
        ////////////////ProjectileCollision
        for (iter eit = eContainer.SpriteVector.begin(); eit < eContainer.SpriteVector.end(); eit++)
        {
            if ((*eit)->mType == 0 && (*it)->mSprite.getGlobalBounds().intersects((*eit)->mSprite.getGlobalBounds()))
            {
                (*eit)->isAlive = false;
                (*eit)->mState = 1;
                
            }
        }
        //////////////////Player Collision
        if ((*it)->mSprite.getGlobalBounds().left == player.ReturnSprite().getGlobalBounds().left + player.ReturnSprite().getGlobalBounds().width)
        {
            (*it)->mSprite.move(4, 0);
        }

    }


   //ENTITY UPDATES---------------------------------------------------------------------------------------
    for (iter it = eContainer.SpriteVector.begin(); it < eContainer.SpriteVector.end(); it++)
    {
        
        if ((*it)->isAlive == true && (*it)->mType == 1)
        {
            (*it)->mSprite.move((*it)->mVelocity.x, (*it)->mVelocity.y);
            (*it)->mVelocity.y += 0.3;
        }
         
        
        if ((*it)->mSprite.getPosition().y <= 600 && (*it)->mType == 0)
        {
            if ((*it)->mDirection == true)
            {
            (*it)->mSprite.move(5, 0);
            }
            if ((*it)->mDirection == false)
            {
                (*it)->mSprite.move(-5, 0);
            }
            std::cout << "Moving...." << (*it)->mType << "\n";
        }
        

        
        if ((*it)->isAlive == true && (*it)->mType == 1 && ((*it)->mSprite.getPosition().y >= 601 || (*it)->mSprite.getPosition().y <= -1))
            {
                (*it)->isAlive = false;
                (*it)->mState = 2;
            }
        
        


        for (unsigned int b = 0; b < lContainer.LevelVector.size(); b++)
        {
            
            if (((*it)->mSprite.getPosition().y >= 601 || ((*it)->mSprite.getGlobalBounds().intersects(lContainer.LevelVector[b].mSprite.getGlobalBounds()))) && ((*it)->mType == 0) )
            {
                (*it)->isAlive = false;
                (*it)->mState = 1;
                std::cout << "Container size..." << eContainer.SpriteVector.size() << "\n";
                 std::cout << "imageSelect..." << (*it)->imageSelect << "\n";
            }
        }
            

        
        
    }
   
}