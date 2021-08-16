//
//  sounds.h
//  mygame
//
//  Created by Ryan Mccoy on 2/24/14.
//  Copyright (c) 2014 Ryan Mccoy. All rights reserved.
//

#ifndef __mygame__sounds__
#define __mygame__sounds__

#include <iostream>
#include <SFML/Audio.hpp>
#include "ResourcePath.hpp"


class Sounds
{
public:
    sf::SoundBuffer* mPistolBuff = new sf::SoundBuffer;
    Sounds()
    {
        mPistolBuff->loadFromFile(resourcePath() + "pistol.wav");
    }
};

#endif /* defined(__mygame__sounds__) */
