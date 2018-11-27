//
//  GameServer.cpp
//  RedStarDungeonPartyGameServer
//
//  Created by Bob Desaunois on 05/11/2018.
//  Copyright © 2018 Bob Desaunois. All rights reserved.
//

#include "GameServer.hpp"

OpenWorldGameServer::GameServer::GameServer
    ()
{
    
    this->log ("Booting up GameServer...");
    
    this->networkingServer = new NetworkingServer;
    
};
