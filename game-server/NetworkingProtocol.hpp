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

#include "PlayerEventType.hpp"
#include "PlayerEvent.hpp"
#include "PlayerEventTypeResolver.hpp"

namespace OpenWorldGameServer
{
    
    class NetworkingProtocol
    {
      
    private:
      
        PlayerEventTypeResolver playerEventTypeResolver;
        
    public:
        
        PlayerEvent parse (std::string data);
        
    };
    
}

#endif /* NetworkingProtocol_hpp */