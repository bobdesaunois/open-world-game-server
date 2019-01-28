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
//    this->eventHandler     = new EventHandler ();
    
}

void
OpenWorldGameServer::NetworkingServerLogic::handlePlayerEvents
    ()
{
    
    for (auto playerEventPtr : this->networkingServer->getPlayerEventBuffer())
    {
        
        std::cout << "This event is an " << playerEventPtr.get()->first;
        
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
