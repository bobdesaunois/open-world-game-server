//
//  PlayerEventTypeResolver.hpp
//  game-server
//
//  Created by Bob Desaunois on 12/11/2018.
//  Copyright © 2018 Bob Desaunois. All rights reserved.
//

#ifndef PlayerEventTypeResolver_hpp
#define PlayerEventTypeResolver_hpp

#include <string>

#include "PlayerEventType.hpp"
#include "ServerComponent.hpp"

namespace OpenWorldGameServer
{
    
    class PlayerEventTypeResolver : public ServerComponent
    {
        
    private:
        
    public:
        
        std::string     resolve (PlayerEventType eventType);
        PlayerEventType resolve (std::string eventTypeString);
        
    };
    
}

#endif /* PlayerEventTypeResolver_hpp */
