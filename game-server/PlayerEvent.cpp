//
//  PlayerEvent.cpp
//  game-server
//
//  Created by Bob Desaunois on 12/11/2018.
//  Copyright © 2018 Bob Desaunois. All rights reserved.
//

#include "PlayerEvent.hpp"

OpenWorldGameServer::PlayerEvent::PlayerEvent
    (PlayerEventType type, std::vector<std::string> values)
{
    
    this->type   = type;
    this->values = values;
    
}

std::string
OpenWorldGameServer::PlayerEvent::getValue
    (int index)
{
    
    return this->values.at (index);
    
};

OpenWorldGameServer::PlayerEventType
OpenWorldGameServer::PlayerEvent::getType
    ()
{
    
    return this->type;
    
};
