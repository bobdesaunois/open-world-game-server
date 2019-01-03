//
//  NetworkingProtocol.hpp
//  game-server
//
//  Created by Bob Desaunois on 12/11/2018.
//  Copyright © 2018 Bob Desaunois. All rights reserved.
//

#ifndef NetworkingProtocol_hpp
#define NetworkingProtocol_hpp

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <boost/algorithm/string.hpp>

#include "ServerComponent.hpp"
#include "PlayerEventTypeResolver.hpp"
#include "HelloEvent.hpp"

#define NETWORKING_PROTOCOL_DELIMITER ','

namespace OpenWorldGameServer
{
    
    class NetworkingProtocol : public ServerComponent
    {
      
    private:
      
        PlayerEventTypeResolver playerEventTypeResolver;
        
    public:
        
        /*
         * TODO: Parse should return an std::pair with the TYPE
         * and a vector with the variables needed for construction
         * and pass *that* to the event builder later on in
         * the NetworkingServer.
         */
        std::pair<PlayerEventType, std::vector<std::string>> parse (std::string data);
        
    };
    
}

#endif /* NetworkingProtocol_hpp */
