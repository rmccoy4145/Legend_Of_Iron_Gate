//
//  textures.h
//  mygame
//
//  Created by Ryan Mccoy on 2/22/14.
//  Copyright (c) 2014 Ryan Mccoy. All rights reserved.
//

#ifndef __mygame__textures__
#define __mygame__textures__

#include <iostream>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"

class Textures
{
public:
    sf::Texture* fireball = new sf::Texture;
    sf::Texture* particle = new sf::Texture;;
    sf::Texture* particle1 = new sf::Texture;;
    sf::Texture* ground = new sf::Texture;;
    Textures()
    {
        fireball->loadFromFile(resourcePath() + "fireball.png");
        particle1->loadFromFile(resourcePath() + "particle1.gif");
        particle->loadFromFile(resourcePath() + "particle.gif");
        ground->loadFromFile(resourcePath() + "Mario-block.gif");
    }
    
};



#endif /* defined(__mygame__textures__) */
