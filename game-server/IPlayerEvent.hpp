//
//  IPlayerEvent.hpp
//  game-server
//
//  Created by Bob Desaunois on 10/12/2018.
//  Copyright © 2018 Bob Desaunois. All rights reserved.
//

#ifndef IPlayerEvent_hpp
#define IPlayerEvent_hpp

#include <vector>
#include <string>
#include "PlayerEventType.hpp"

namespace OpenWorldGameServer {
    
    class IPlayerEvent
    {
      
    private:
        
    public:
        
        IPlayerEvent (std::vector<std::string>) {};
        
        virtual ~IPlayerEvent () = default;
        virtual std::string     getValue (int index) {};
        virtual PlayerEventType getType () {};
        
    };
    
}

#endif /* IPlayerEvent_hpp */
