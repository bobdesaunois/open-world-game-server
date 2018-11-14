//
//  PlayerConnection.hpp
//  game-server
//
//  Created by Bob Desaunois on 11/11/2018.
//  Copyright © 2018 Bob Desaunois. All rights reserved.
//

#ifndef ClientConnection_hpp
#define ClientConnection_hpp

#include <string>
#include "PlayerPosition.hpp"


namespace OpenWorldGameServer
{
    
    class PlayerConnection
    {
        
    private:
        
        PlayerPosition position;
        std::string hostname;
        std::string username;
        
    public:
        
        PlayerConnection (std::string hostname, std::string username);
        
    };
    
}

#endif /* PlayerConnection_hpp */
