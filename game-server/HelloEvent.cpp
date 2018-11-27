//
//  HelloEvent.cpp
//  game-server
//
//  Created by Bob Desaunois on 19/11/2018.
//  Copyright © 2018 Bob Desaunois. All rights reserved.
//

#include "PlayerEventBuilder.hpp"
#include "HelloEvent.hpp"

void
OpenWorldGameServer::HelloEvent::handle
    ()
{

    std::cout << "i'm an hello event owo" << std::endl;

};
