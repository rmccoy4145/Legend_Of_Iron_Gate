//
//  enemy.h
//  mygame
//
//  Created by Ryan Mccoy on 2/9/14.
//  Copyright (c) 2014 Ryan Mccoy. All rights reserved.
//

#ifndef __mygame__enemy__
#define __mygame__enemy__

#include <iostream>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include "player.h"
#include "textures.h"

class Enemy
{
public:
    sf::Sprite mSprite;
    sf::Texture mTexture;
    bool isAlive;
    enum mEnemys {ZOMBIE = 0};
    int mType;
    enum mStates {ALIVE = 0, DIEING = 1, DEAD = 2};
    enum mDirections {LEFT = 0, RIGHT = 1};
    int mDirection;
    int mHealth;
    int mState;
    int mFrameX;
    sf::Time mTime;
    sf::Clock mClock;
    sf::Vector2f mPosition;
    sf::Vector2f mVelocity;
    sf::Vector2f GetPosition(){return mSprite.getPosition();};
    int imageSelect;
    float boundingBoxBottom(){return (mSprite.getGlobalBounds().top + mSprite.getGlobalBounds().height);};
    float boundingBoxRight(){return (mSprite.getGlobalBounds().top + mSprite.getGlobalBounds().width);};
    float boundingBoxTop(){return mSprite.getGlobalBounds().top;};
    float boundingBoxLeft(){return mSprite.getGlobalBounds().left;};
    virtual void Animations(Player& player) {std::cout << "Enemy Virtual Animation function" << "\n";};

};
class Zombie : public Enemy
{
public:
    Zombie(sf::Vector2f mPosition)
    {
        mTexture.loadFromFile(resourcePath() + "zombie2.png");
        mFrameX = 6;
        mSprite.setTextureRect(sf::IntRect(mFrameX * 56, 0 * 100, 56, 100));
        mSprite.setTexture(mTexture);
        mType = ZOMBIE;
        isAlive = true;
        mState = ALIVE;
        mSprite.setPosition(mPosition.x, mPosition.y);
        mDirection = RIGHT;
        mHealth = 10;

    }
    void Animations(Player& player);
};
class EnemyContainer
{
public:
    std::vector<std::unique_ptr<Enemy>> EnemyVector;
};
typedef std::vector<std::unique_ptr<Enemy>>::iterator enemyiter;

#endif /* defined(__mygame__enemy__) */
