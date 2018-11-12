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

namespace OpenWorldGameServer
{
    
    class PlayerEvent
    {
      
    private:
        
        PlayerEventType type;
        
        
    public:
        
        PlayerEvent (PlayerEventType type);
        
    };
    
}

#endif /* PlayerEvent_hpp */
