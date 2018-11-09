//
//  NetworkingServer.hpp
//  RedStarDungeonPartyGameServer
//
//  Created by Bob Desaunois on 05/11/2018.
//  Copyright © 2018 Bob Desaunois. All rights reserved.
//

#ifndef NetworkingServer_hpp
#define NetworkingServer_hpp

#include "ServerComponent.hpp"
#include <SFML/Network.hpp>

namespace RedStarDungeonParty
{
    
    class NetworkingServer : public ServerComponent
    {
        
    public:
        
        NetworkingServer ();
        
    };
    
}

#endif /* NetworkingServer_hpp */
