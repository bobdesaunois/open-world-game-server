//
//  NetworkingProtocol.cpp
//  game-server
//
//  Created by Bob Desaunois on 12/11/2018.
//  Copyright © 2018 Bob Desaunois. All rights reserved.
//

#include "NetworkingProtocol.hpp"

OpenWorldGameServer::PlayerEvent
OpenWorldGameServer::NetworkingProtocol::parse (std::string data)
{
    
    
    std::vector<std::string> dataVector;
    boost::split (dataVector, data, [] (char c) {return c = ',';});
    
    PlayerEventType playerEventType = this->playerEventTypeResolver.resolve (dataVector.at (0));
    PlayerEvent     playerEvent     = *new PlayerEvent (playerEventType);
    
    return playerEvent;
    
};
