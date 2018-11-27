//
//  NetworkingServerLogic.cpp
//  game-server
//
//  Created by Bob Desaunois on 24/11/2018.
//  Copyright © 2018 Bob Desaunois. All rights reserved.
//

#include "NetworkingServerLogic.hpp"

bool OpenWorldGameServer::NetworkingServerLogic::getRunning () { return running; };
void OpenWorldGameServer::NetworkingServerLogic::setRunning (bool running) { this->running = running; };

OpenWorldGameServer::NetworkingServerLogic::NetworkingServerLogic
    (NetworkingServer* networkingServerPtr)
{
    
    this->networkingServer = networkingServerPtr;
    
}

void
OpenWorldGameServer::NetworkingServerLogic::handlePlayerEvents
    ()
{
    
    for (std::shared_ptr<PlayerEvent> playerEventPtr : this->networkingServer->getPlayerEventBuffer())
    {
        
        playerEventPtr.get ()
            ->handle ();
        
    }
    
}

void
OpenWorldGameServer::NetworkingServerLogic::loop
    ()
{
    
    while (running)
    {
        
        this->handlePlayerEvents ();
        
    }
    
};
