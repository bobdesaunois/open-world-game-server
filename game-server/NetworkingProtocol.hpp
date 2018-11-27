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
         * TODO: Parse should return an std::set with the TYPE
         * and the variables needed for construction
         * and pass *that* to the event builder later on in
         * the NetworkingServer.
         */
        PlayerEvent parse (std::string data);
        
    };
    
}

#endif /* NetworkingProtocol_hpp */
