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
#include "IPlayerEvent.hpp"
#include "PlayerEvent.hpp"
#include "PlayerEventType.hpp"
#include "PlayerEventTypeResolver.hpp"
#include "NetworkingProtocol.hpp"
#include "EventHandler.hpp"
#include "NetworkingServerLogic.hpp"
#include "PlayerEventBuilder.hpp"

// Events
#include "HelloEvent.hpp"

#include <SFML/Network.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <vector>
#include <string>
#include <thread>
#include <memory>

#define PORT 1337
#define MAX_CONNECTIONS 6
#define PLAYER_SPAWN_POSITION_X = 0
#define PLAYER_SPAWN_POSITION_Y = 0

namespace OpenWorldGameServer
{
    
    class NetworkingServerLogic;
    
    class NetworkingServer : public ServerComponent
    {
        
    private:
        
        int running = 0;

        sf::UdpSocket           clientSocket;
        NetworkingProtocol      networkingProtocol;
        NetworkingServerLogic*  networkingServerLogic;
        
        std::vector<PlayerConnection>                  playerConnectionPool;
        std::vector<std::shared_ptr<IPlayerEvent>>      playerEventBuffer;
       
    public:
        
        NetworkingServer ();
        
        std::vector<PlayerConnection>& getPlayerConnectionPool ();
        std::vector<std::shared_ptr<IPlayerEvent>>& getPlayerEventBuffer ();
        
        void        listen ();
        void        handleNewConnection (IPlayerEvent helloEvent);
        void        handleNewEvent      (IPlayerEvent playerEvent);
        std::string generatePlayerID ();
    
        
        
    };
    
}

#endif /* NetworkingServer_hpp */
