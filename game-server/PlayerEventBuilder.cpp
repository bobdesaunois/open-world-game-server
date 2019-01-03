//
//  PlayerEventBuilder.cpp
//  game-server
//
//  Created by Bob Desaunois on 19/11/2018.
//  Copyright © 2018 Bob Desaunois. All rights reserved.
//

#include "HelloEvent.hpp"
#include "PlayerEventBuilder.hpp"

OpenWorldGameServer::PlayerEventBuilder::PlayerEventBuilder
    (std::pair<OpenWorldGameServer::PlayerEventType, std::vector<std::string>> pseudoPlayerEvent)
{
    
    this->pseudoPlayerEvent = pseudoPlayerEvent;
    
};

template<class T>
OpenWorldGameServer::PlayerEvent<T>
OpenWorldGameServer::PlayerEventBuilder::build
    ()
{
    
    switch (this->pseudoPlayerEvent.first)
    {
      
        case HELLO:
            return new PlayerEvent<HelloEvent> (pseudoPlayerEvent.second);
    
//        case UPDATE_POSITION:
//
// 
//        case DAMAGE_ENTITY:
            
            
        default:
            std::cout << "Unrecogninzed type at PlayerEventBuilder::build :(" << std::endl;
            exit (1);
            
    };
    
};
