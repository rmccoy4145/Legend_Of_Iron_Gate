//
//  player.h
//  mygame
//
//  Created by Ryan Mccoy on 2/5/14.
//  Copyright (c) 2014 Ryan Mccoy. All rights reserved.
//

#ifndef __mygame__player__
#define __mygame__player__

#include <iostream>
#include <SFML/Graphics.hpp>
#include "entity-level.h"

//Player Class

    class Player
    {
        
    private:
        
    public:
        Player();
        enum mStates {ALIVE = 0, DIEING = 1, DEAD = 2};
        int mState;
        enum mActions {IDLE = 0, THROWFIREBALL = 1};
        int mAction;
        int mHealth;
        float boundingBoxBottom(){return (Sprite_.getGlobalBounds().top + Sprite_.getGlobalBounds().height);};
        float boundingBoxRight(){return (Sprite_.getGlobalBounds().top + Sprite_.getGlobalBounds().width);};
        float boundingBoxTop(){return Sprite_.getGlobalBounds().top;};
        float boundingBoxLeft(){return Sprite_.getGlobalBounds().left;};
         sf::Vector2f GetPosition(){return Sprite_.getPosition();};
        sf::Sprite ReturnSprite();
        //void Gravity(std::vector<Level>& Vector);
        float ReturnVector();
        void playerMove(float vX, float vY);
        void playerAnimation (int sX, int sY, int width);
        sf::Texture GetTexture();
        void sDirection(bool sD);
        bool ReturnDirection();
        sf::Vector2f PlayerBounds;
        
        void Movements(bool &leftPressed_, bool &rightPRessed_, LevelContainer& lContainer, bool &spacePressed_);
        void Animations();
        float GetPlayerPositionX();
        float GetPlayerPositionY();
        float GetPositionY();
        int iPosX;
        int iPosY;
        friend class LevelContainer;
        bool ReturnSpriteDirection();
        
        //Used to be Private
        sf::Sprite Sprite_;
        sf::Texture simage_;
        sf::Vector2f velocity_;
        sf::Vector2i source_;
        sf::Vector2i playerPos_;
        int spriteWidth;
        bool spriteDirection_;
        
        
        float moveSpeed_;
        
        bool leftPressed_;
        bool rightPressed_;
        bool spacePressed_;
        sf::Time time_;
        sf::Clock clock_;
        int naFrameX_;
        int naFrameY_;

    };


#endif /* defined(__mygame__player__) */
