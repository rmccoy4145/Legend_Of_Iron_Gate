//
//  entity-level.h
//  mygame
//
//  Created by Ryan Mccoy on 2/6/14.
//  Copyright (c) 2014 Ryan Mccoy. All rights reserved.
//

#ifndef __mygame__entity_level__
#define __mygame__entity_level__

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ResourcePath.hpp"
#include "textures.h"

class Entity
{
public:
    sf::Sprite mSprite;
    sf::Texture mTexture;
    bool isAlive;
    enum mEntitys {PROJECTILE = 0, PARTICLE = 1};
    int mType;
    enum mStates {ALIVE = 0, DIEING = 1, DEAD = 2};
    enum mDirections {LEFT = 0, RIGHT = 1};
    int mDirection;
    int mState;
    sf::Sound mSound;
    sf::Vector2f mPosition;
    sf::Vector2f mVelocity;
    virtual sf::Vector2f GetPosition(){return mSprite.getPosition(); std::cout << "Base/n";};
    int imageSelect;
    bool isDestroyed(){return !isAlive;};
    
    
};
class Fireball : public Entity
{
public:
    Fireball(sf::Vector2f mPosition, sf::Texture& tTexture, sf::SoundBuffer& mSound)
    {
        this->mSound.setBuffer(mSound);
        mSprite.setTextureRect(sf::IntRect(0 * 60, 0 * 60, 60, 60));
        mSprite.setTexture(tTexture);
        mType = PROJECTILE;
        isAlive = true;
        mState = ALIVE;
        mSprite.setPosition(mPosition.x, mPosition.y);
        mDirection = RIGHT;
        
    }
    sf::Vector2f GetPosition(){return mSprite.getPosition();};
};

class ExplosionParticle : public Entity
{
    public:
    ExplosionParticle(sf::Vector2f mPosition, sf::Texture& tTexture, sf::Texture& tTexture1)
    {
        int imageSelect = rand() % 5;
        if (imageSelect == 2)
        {
            mSprite.setTexture(tTexture);
        }
        else
        {
            mSprite.setTexture(tTexture1);
        }
        mVelocity.x = rand() % 31 + (-15);
        mVelocity.y = rand() % 31 + (-15);
        mSprite.setPosition(mPosition.x, mPosition.y);
        isAlive = true;
        mType = PARTICLE;
        mState = ALIVE;

    }
    sf::Vector2f GetPosition(){return mSprite.getPosition();};
};

class EntityContainer
{
public:
    std::vector<std::unique_ptr<Entity>>  SpriteVector;
};
typedef std::vector<std::unique_ptr<Entity>>::iterator iter;


class Level
{
public:
    sf::Sprite mSprite;
    sf::Texture mTexture;
    std::string mType;
    friend class Player;
    float boundingBoxBottom(){return (mSprite.getGlobalBounds().top + mSprite.getGlobalBounds().height);};
    float boundingBoxRight(){return (mSprite.getGlobalBounds().top + mSprite.getGlobalBounds().width);};
    float boundingBoxTop(){return mSprite.getGlobalBounds().top;};
    float boundingBoxLeft(){return mSprite.getGlobalBounds().left;};

};

class Ground : public Level
{
public:
    Ground(sf::Texture& tTexture){
        mSprite.setTexture(tTexture);
        mType = "Ground";
    }
    
};

class LevelContainer
{
public:
    std::vector<Level> LevelVector;
};

#endif /* defined(__mygame__entity_level__) */
