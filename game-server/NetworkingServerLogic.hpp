//
//  NetworkingServerLogic.hpp
//  game-server
//
//  Created by Bob Desaunois on 24/11/2018.
//  Copyright © 2018 Bob Desaunois. All rights reserved.
//

#ifndef NetworkingServerLogic_hpp
#define NetworkingServerLogic_hpp

#include "ServerComponent.hpp"
#include "NetworkingServer.hpp"
#include "PlayerEvent.hpp"
#include "HelloEvent.hpp"
#include <memory>

namespace OpenWorldGameServer{

    class NetworkingServer;
    
    class NetworkingServerLogic : public ServerComponent
    {
        
    private:
        
        bool running = false;
        NetworkingServer* networkingServer;
        
    public:
        
        NetworkingServerLogic (NetworkingServer* networkingServerPtr);
        
        bool getRunning ();
        void setRunning (bool running);
        
        void loop ();
        void handlePlayerEvents ();
        
    };
    
}

#endif /* NetworkingServerLogic_hpp */
