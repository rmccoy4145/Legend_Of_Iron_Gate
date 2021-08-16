//
//  enemy.cpp
//  mygame
//
//  Created by Ryan Mccoy on 2/9/14.
//  Copyright (c) 2014 Ryan Mccoy. All rights reserved.
//

#include "enemy.h"

void Zombie::Animations(Player& player)
{
   
        if (mState == ALIVE)
        {
            if (player.ReturnSprite().getPosition().x < mSprite.getPosition().x)
            {
            mSprite.setTextureRect(sf::IntRect(mFrameX * 56, 0 * 100, 56, 100));
            
            if (mTime >= sf::seconds(0.15))
            {
                mFrameX--;
                mTime = mClock.restart();
                if (mFrameX * 56 < 0)
                {mFrameX = 6;}
                if (mFrameX >2)
                {mSprite.move(-4,0);}
            }
            }
            if (player.ReturnSprite().getPosition().x > mSprite.getPosition().x)
            {
                mSprite.setTextureRect(sf::IntRect(mFrameX * 56, 0 * 100, -56, 100));
                //mFrameX = ;
                if (mTime >= sf::seconds(0.15))
                {
                    mFrameX--;
                    mTime = mClock.restart();
                    if (mFrameX * 56 < 0 || mFrameX == 0)
                    {mFrameX = 7;}
                    if (mFrameX >2)
                    {mSprite.move(4,0);}
                }
            }
            if (mState == DIEING)
            {
                mSprite.setTextureRect(sf::IntRect(mFrameX * 56, 0 * 100, -56, 100));
                if (mTime >= sf::seconds(0.15))
                {
                    mFrameX--;
                    mTime = mClock.restart();
                    if (mFrameX == 0)
                    {mState = DEAD;}

                }

            }
            mTime = mClock.getElapsedTime();
        }
    
    
    std::cout << "Zombie Frame" << mFrameX << "\n";
    std::cout << "Zombie Animation function" << "\n";
}