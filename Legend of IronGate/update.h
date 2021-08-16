//
//  update.h
//  mygame
//
//  Created by Ryan Mccoy on 2/6/14.
//  Copyright (c) 2014 Ryan Mccoy. All rights reserved.
//

#ifndef __mygame__update__
#define __mygame__update__

#include <iostream>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include "player.h"
#include "entity-level.h"
#include "enemy.h"
#include "sounds.h"


class Update
{
public:
    friend class Player;
    void Updates(LevelContainer& lContainer, EntityContainer& eContainer, EnemyContainer& enContainer, Player& player, Textures& textures);
    void AddObjects(LevelContainer& lContainer, EntityContainer& eContainer, EnemyContainer& enContainer, Player& player, Textures& textures, Sounds& sound);
    void RemoveObjects(LevelContainer& lContainer, EntityContainer& eContainer, EnemyContainer& enContainer, Player& player, Textures& textures);
};

#endif /* defined(__mygame__update__) */
