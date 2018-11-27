//
//  GameServer.hpp
//  RedStarDungeonPartyGameServer
//
//  Created by Bob Desaunois on 05/11/2018.
//  Copyright © 2018 Bob Desaunois. All rights reserved.
//

#ifndef GameServer_hpp
#define GameServer_hpp

#include "NetworkingServer.hpp"
#include "ServerComponent.hpp"

namespace OpenWorldGameServer
{
    
    class GameServer : public ServerComponent
    {
        
    private:
        
    public:
        
        GameServer ();
        
        NetworkingServer* networkingServer;
        
    };
    
}

#endif /* GameServer_hpp */
