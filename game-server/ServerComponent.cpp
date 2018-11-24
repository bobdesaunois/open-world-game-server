//
//  ServerComponent.cpp
//  RedStarDungeonPartyGameServer
//
//  Created by Bob Desaunois on 05/11/2018.
//  Copyright © 2018 Bob Desaunois. All rights reserved.
//

#include "ServerComponent.hpp"

void
OpenWorldGameServer::ServerComponent::log
    (std::string message)
{
  
    std::cout
//        << "[" << typeid (this).name () << "] "
        << "[Server] "
        << message
        << std::endl;
    
};
