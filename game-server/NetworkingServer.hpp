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
#include "PlayerConnection.hpp"
#include "NetworkingProtocol.hpp"
#include "PlayerEvent.hpp"
#include "PlayerEventType.hpp"
#include "PlayerEventTypeResolver.hpp"

#include <SFML/Network.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <vector>
#include <string>

#define PORT 1337
#define MAX_CONNECTIONS 6
#define PLAYER_SPAWN_POSITION_X = 0
#define PLAYER_SPAWN_POSITION_Y = 0

namespace OpenWorldGameServer
{
    
    class NetworkingServer : public ServerComponent
    {
        
    private:
        
        int running = 0;
        sf::UdpSocket      clientSocket;
        NetworkingProtocol networkingProtocol;
        
        std::vector<PlayerConnection> playerConnectionPool;
       
        void listen ();
        void handleNewConnection (PlayerEvent helloEvent);
        void logNewConnection (PlayerEvent helloEvent);
        void handleNewEvent (PlayerEvent playerEvent);
        std::string generatePlayerID ();
    
    public:
        
        NetworkingServer ();
        std::vector<PlayerConnection>* getPlayerConnectionPool ();
        
    };
    
}

#endif /* NetworkingServer_hpp */
