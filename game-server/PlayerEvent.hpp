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
#include <vector>

namespace OpenWorldGameServer
{
    
    class PlayerEvent
    {
      
    private:
        
        PlayerEventType type;
        std::vector<std::string> values;
        
    public:
        
        PlayerEvent (PlayerEventType type);
        std::string getValue (int index);
        PlayerEventType getType ();
        
    };
    
}

#endif /* PlayerEvent_hpp */
