//
//  NetworkingProtocol.cpp
//  game-server
//
//  Created by Bob Desaunois on 12/11/2018.
//  Copyright © 2018 Bob Desaunois. All rights reserved.
//

#include "HelloEvent.hpp"
#include "PlayerEventBuilder.hpp"
#include "NetworkingProtocol.hpp"

// TODO: this method is pretty ugly, should fix and apply SRP
OpenWorldGameServer::PlayerEvent
OpenWorldGameServer::NetworkingProtocol::
parse
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
    
    PlayerEventType playerEventType
        = this->playerEventTypeResolver.resolve (dataVector.at (0));
    
    // TODO: I don't want to maintain new types here at all :(
    // I should probably move this to the PlayerEventBuilder somehow
    // or somewhere else where this behavior can be managed.
    switch (playerEventType)
    {
            
        case PlayerEventType::HELLO:
        {
            
            auto eventBuilder = *new PlayerEventBuilder<HelloEvent> ();
            return eventBuilder.build ();
            
        }
            
        default:
            this->log ("PARSER COULD NOT FIGURE OUT TYPE :(");
            exit (0);
            
    }
    
};
