//
//  HelloEvent.hpp
//  game-server
//
//  Created by Bob Desaunois on 19/11/2018.
//  Copyright © 2018 Bob Desaunois. All rights reserved.
//

#ifndef HelloEvent_hpp
#define HelloEvent_hpp

#include <iostream>
#include "NetworkingServer.hpp"
#include "PlayerEvent.hpp"

//class NetworkingServer;

namespace OpenWorldGameServer
{
    
    class HelloEvent : public PlayerEvent
    {
        
    private:
        
    public:
        
        HelloEvent ()
        {
            
        };
        
        void handle ();
        
//        HelloEvent (std::vector<std::string> values)
//            : PlayerEvent (PlayerEventType::HELLO, values)
//        {
//        };
        
    };
    
}

#endif /* HelloEvent_hpp */
