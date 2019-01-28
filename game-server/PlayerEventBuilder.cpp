//
//  PlayerEventBuilder.cpp
//  game-server
//
//  Created by Bob Desaunois on 19/11/2018.
//  Copyright © 2018 Bob Desaunois. All rights reserved.
//

//#include "HelloEvent.hpp"
#include "PlayerEventBuilder.hpp"

OpenWorldGameServer::PlayerEventBuilder::PlayerEventBuilder
    (std::pair<OpenWorldGameServer::PlayerEventType, std::vector<std::string>> pseudoPlayerEvent)
{
    
    this->pseudoPlayerEvent = pseudoPlayerEvent;
    
};

//OpenWorldGameServer::IPlayerEvent
//OpenWorldGameServer::PlayerEventBuilder::build
//    ()
//{
//
//    switch (this->pseudoPlayerEvent.first)
//    {
//
//        case HELLO:
//            return *new PlayerEvent<HelloEvent> (
//                this->pseudoPlayerEvent.second
//            );
//
//        default:
//            std::cout << "Unrecogninzed type at PlayerEventBuilder::build :(" << std::endl;
//            exit (1);
//
//    };
//
//};
