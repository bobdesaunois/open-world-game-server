//
//  PlayerEvent.hpp
//  game-server
//
//  Created by Bob Desaunois on 12/11/2018.
//  Copyright © 2018 Bob Desaunois. All rights reserved.
//

#ifndef PlayerEvent_hpp
#define PlayerEvent_hpp

#include "PlayerEventType.hpp"
#include "ServerComponent.hpp"
#include <vector>

namespace OpenWorldGameServer
{
    
    template<class T>
    class PlayerEvent : public ServerComponent
    {
      
    private:
        
        PlayerEventType          type; // TODO: Safely remove this
        std::vector<std::string> values;
        T                        event;
        
    public:
        
        PlayerEvent ();
        
        std::string     getValue (int index);
        PlayerEventType getType  ();
        T*              getEvent ();
        
        void            handle ();
        
    };
    
}

#endif /* PlayerEvent_hpp */
