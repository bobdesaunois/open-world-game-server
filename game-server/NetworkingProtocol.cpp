//
//  NetworkingProtocol.cpp
//  game-server
//
//  Created by Bob Desaunois on 12/11/2018.
//  Copyright © 2018 Bob Desaunois. All rights reserved.
//

#include "NetworkingProtocol.hpp"

OpenWorldGameServer::PlayerEvent
OpenWorldGameServer::NetworkingProtocol::parse
    (std::string data)
{
    
    std::vector<std::string> dataVector;
    
    int captureStart = 0;
    int captureIndex = 0;
    for (char& c : data)
    {
        
        if (data[captureIndex] == NETWORKING_PROTOCOL_DELIMITER)
        {
            
            dataVector.push_back (data.substr (captureStart, captureIndex - captureStart));
            
            captureStart++; // TODO: why is this here lmao
            captureStart = (captureIndex + 1);
            
        }
        
        captureIndex++;
        
        if (captureIndex == data.length ())
            dataVector.push_back (data.substr (captureStart, captureIndex));
        
    }
    
    PlayerEventType playerEventType = this->playerEventTypeResolver.resolve (dataVector.at (0));
    PlayerEvent     playerEvent     = *new PlayerEvent (playerEventType, dataVector);
    
    return playerEvent;
    
};
