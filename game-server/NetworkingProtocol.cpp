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

// TODO: this method is pretty ugly, should abstract and apply SRP
std::pair<OpenWorldGameServer::PlayerEventType, std::vector<std::string>>
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
    
    std::string interpretedType     = dataVector.at (0);
    std::string interpretedEntity   = dataVector.at (1);
    
    PlayerEventType playerEventType
        = this->playerEventTypeResolver.resolve (interpretedType);
    
    /*
     We do not construct a real playerEvent here with an event accordingly.
     Instead we create an std::pair that serves as a pseudo PlayerEvent for a very good reason.
     The reason being that we cannot reliably handle the generic type of the PlayerEvent type just yet.
     Hence why we move this event down the process as a pseudo first to later on construct it through the
     PlayerEventBuilder.
     */
    
    auto pseudoPlayerEvent = *new std::pair<PlayerEventType, std::vector<std::string>> (playerEventType, dataVector);
    
    return pseudoPlayerEvent;
    
    
    /*
     TODO: This is now obsolete, should remove this if I'm certain I won't be using it anymore.
     */
    // TODO: I don't want to maintain new types here at all :(
    // I should probably move this to the PlayerEventBuilder somehow
    // or somewhere else where this behavior can be managed.
//    switch (playerEventType)
//    {
//
//        case PlayerEventType::HELLO:
//        {
//
//            auto eventBuilder = *new PlayerEventBuilder<HelloEvent> ();
//            return eventBuilder.build ();
//
//        }
//
//        default:
//            this->log ("PARSER COULD NOT FIGURE OUT TYPE :(");
//            exit (0);
//
//    }
    
};
