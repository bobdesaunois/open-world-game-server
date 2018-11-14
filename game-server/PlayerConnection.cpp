//
//  PlayerConnection.cpp
//  game-server
//
//  Created by Bob Desaunois on 11/11/2018.
//  Copyright © 2018 Bob Desaunois. All rights reserved.
//

#include "PlayerConnection.hpp"

OpenWorldGameServer::PlayerConnection::PlayerConnection
    (std::string hostname, std::string username)
        : position (0, 0)
{
    
    this->hostname = hostname;
    this->username = username;

};
