//
//  PlayerEventTypeResolver.cpp
//  game-server
//
//  Created by Bob Desaunois on 12/11/2018.
//  Copyright © 2018 Bob Desaunois. All rights reserved.
//

#include "PlayerEventTypeResolver.hpp"

std::string
OpenWorldGameServer::PlayerEventTypeResolver::resolve (PlayerEventType eventType)
{
    
    switch (eventType)
    {
            
        case UPDATE_POSITION:
            return "updatePosition";
            
        case DAMAGE_ENTITY:
            return "damageEntity";
        
        default:
            this->log ("UNRECOGNIZED EVENT TYPE!?");
            exit (0);
            
    }
    
};

OpenWorldGameServer::PlayerEventType
OpenWorldGameServer::PlayerEventTypeResolver::resolve (std::string eventTypeString)
{
    
    if ((this->resolve (UPDATE_POSITION)).compare (eventTypeString) == 1)
        return UPDATE_POSITION;
    
    if ((this->resolve (DAMAGE_ENTITY)).compare (eventTypeString) == 1)
        return DAMAGE_ENTITY;
    
    this->log ("UNRECOGNIZED EVENT TYPE!?");
    exit (0);
    
};
