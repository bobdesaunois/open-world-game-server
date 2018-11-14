//
//  PlayerEventTypeResolver.cpp
//  game-server
//
//  Created by Bob Desaunois on 12/11/2018.
//  Copyright © 2018 Bob Desaunois. All rights reserved.
//

#include "PlayerEventTypeResolver.hpp"

std::string
OpenWorldGameServer::PlayerEventTypeResolver::resolve
    (PlayerEventType eventType)
{
    
    switch (eventType)
    {
            
        case HELLO:
            return (std::string ) "hello";
            
        case UPDATE_POSITION:
            return (std::string) "updatePosition";
            
        case DAMAGE_ENTITY:
            return (std::string) "damageEntity";
        
        default:
            this->log ("UNRECOGNIZED EVENT TYPE!?");
            exit (0);
            
    }
    
};

OpenWorldGameServer::PlayerEventType
OpenWorldGameServer::PlayerEventTypeResolver::resolve
    (std::string eventTypeString)
{
    
    if ((this->resolve (HELLO)).compare (eventTypeString) == 0)
        return HELLO;
    
    if ((this->resolve (UPDATE_POSITION)).compare (eventTypeString) == 0)
        return UPDATE_POSITION;
    
    if ((this->resolve (DAMAGE_ENTITY)).compare (eventTypeString) == 0)
        return DAMAGE_ENTITY;
    
    this->log ("ERROR UNRECOGNIZED EVENT TYPE in PlayerEventTypeResolver::resolve");
    
    exit (0);
    
};
