//
//  player.cpp
//  mygame
//
//  Created by Ryan Mccoy on 2/5/14.
//  Copyright (c) 2014 Ryan Mccoy. All rights reserved.
//

#include "player.h"
#include "ResourcePath.hpp"

    Player::Player()                                                        //-------------Constructor
    {
        simage_.loadFromFile(resourcePath()+"hero_sheet.png");
        Sprite_.setTexture(simage_);
        velocity_.x = 0;
        velocity_.y = 0;
        source_.x = 0;
        source_.y = 0;
        spriteDirection_ = true;
        Sprite_.setPosition( 0, 0);
        iPosX = Sprite_.getPosition().x;
        iPosY = Sprite_.getPosition().y;
        mHealth = 100;
        
        //movement variables
        moveSpeed_ = 0;
        leftPressed_ = false;
        rightPressed_ = false;
        naFrameX_ = 0;
        naFrameY_ = 0;
    }
    
    float Player::GetPlayerPositionX()
    {
        return Sprite_.getPosition().x;
        
    }
    
    float Player::GetPlayerPositionY()
    {
        return Sprite_.getPosition().y;
        
    }
    
    sf::Sprite Player::ReturnSprite()                                       //--------Return Sprite_
    {
        return Sprite_;
    }
    
    void Player::Animations()                                               //------------------------------Player image direction
    {
        
        if (spriteDirection_ == false)
        {
            Sprite_.setTextureRect(sf::IntRect(naFrameX_ * 80, naFrameY_ * 80, 80, 80));
            if (moveSpeed_ == 0)
            {
                naFrameX_ = 0;
                naFrameY_ = 1;
            }
        }
        if (spriteDirection_ == true)
        {
            Sprite_.setTextureRect(sf::IntRect(naFrameX_ * 80, naFrameY_ * 80, 80, 80));
        
            if (moveSpeed_ == 0)
            {
                naFrameX_ = 0;
                naFrameY_ = 0;
            }
        }
    }
    
    void Player::Movements(bool &leftPressed_, bool &rightPressed_, LevelContainer& lContainer, bool &spacePressed_)            //----------------Functions for Player movements
    {
        //Start Gravity & Level Collision Checks----------------------
        Sprite_.move(moveSpeed_, 3);
        for (unsigned int b = 0; b < lContainer.LevelVector.size(); b++)
        {
            if ( (Sprite_.getGlobalBounds().top + Sprite_.getGlobalBounds().height) >= lContainer.LevelVector[b].mSprite.getGlobalBounds().top )
            {
                Sprite_.move(moveSpeed_, -3);
            }
        }
        //End Gravity & Level Collision Checks----------------------

        if (leftPressed_ == true)
        {
            spriteDirection_ = false;
            moveSpeed_ = -2.0f;
            naFrameY_ = 3;
            if (time_ >= sf::seconds(0.1))
            {
                naFrameX_++;
                
                time_ = clock_.restart();
                //if (naFrameX_ * -80 <= -simage_.getSize().x || naFrameX_ == 1)
                if (naFrameX_ * 80 > 480)
                {
                    naFrameX_ = 0;
                }
            }
        }
        else if (rightPressed_ == true)
        {
            spriteDirection_ = true;
            moveSpeed_ = 2.0f;
            naFrameY_ = 2;
            if (time_ >= sf::seconds(0.1))
            {
                naFrameX_++;
                time_ = clock_.restart();
                //if (naFrameX_ * 80 >= simage_.getSize().x)
                if (naFrameX_ * 80 >= 480)
                {
                    naFrameX_ = 0;
                }
            }
        }
        else
        {
            moveSpeed_ = 0;
        }
        
        if (spacePressed_ == true)
        {
    
            if ( spriteDirection_ == false)
            {
                naFrameY_ = 4;
                if (time_ >= sf::seconds(0.1))
                {
                naFrameX_++;
                time_ = clock_.restart();
                //if (naFrameX_ * 80 >= simage_.getSize().x)
                if (naFrameX_ * 80 > 320)
                {
                    naFrameX_ = 0;
                }
                }
            }
            else if ( spriteDirection_ == true)
            {
                naFrameY_ = 5;
                if (time_ >= sf::seconds(0.1))
                {
                naFrameX_++;
                time_ = clock_.restart();
                //if (naFrameX_ * 80 >= simage_.getSize().x)
                if (naFrameX_ * 80 > 320)
                {
                    naFrameX_ = 0;
                }
                }
            }
        }
        
        time_ = clock_.getElapsedTime();
    }
    
    bool Player::ReturnSpriteDirection()
    {
        return spriteDirection_;
    }

