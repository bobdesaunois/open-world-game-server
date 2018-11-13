//
//  PlayerEventType.hpp
//  game-server
//
//  Created by Bob Desaunois on 12/11/2018.
//  Copyright © 2018 Bob Desaunois. All rights reserved.
//

#ifndef PlayerEventType_hpp
#define PlayerEventType_hpp

#include <string>
#include <map>

namespace OpenWorldGameServer
{
    
    enum PlayerEventType
    {
     
        HELLO // hello
    ,   UPDATE_POSITION // updatePosition
    ,   DAMAGE_ENTITY // damageEntity
        
    };
    
}

#endif /* PlayerEventType_hpp */
