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
#include "NetworkingProtocol.hpp"
#include "PlayerConnection.cpp"
#include "PlayerEvent.hpp"
#include "PlayerEventType.hpp"
#include "PlayerEventTypeResolver.hpp"

#include <SFML/Network.hpp>
#include <vector>
#include <string>

#define PORT 1337
#define MAX_CONNECTIONS 6;

namespace OpenWorldGameServer
{
    
    class NetworkingServer : public ServerComponent
    {
        
    private:
        
        sf::UdpSocket clientSocket;
        NetworkingProtocol networkingProtocol;
        
        void listen ();
        
        
    public:
        
        NetworkingServer ();
        
    };
    
}

#endif /* NetworkingServer_hpp */
