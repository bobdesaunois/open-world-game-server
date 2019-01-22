//
//  PlayerEventBuilder.hpp
//  game-server
//
//  Created by Bob Desaunois on 19/11/2018.
//  Copyright © 2018 Bob Desaunois. All rights reserved.
//

#ifndef PlayerEventBuilder_hpp
#define PlayerEventBuilder_hpp

#include "ServerComponent.hpp"
#include "PlayerEvent.hpp"
#include "PlayerEventType.hpp"
#include "IPlayerEvent.hpp"

namespace OpenWorldGameServer
{
    
    class PlayerEventBuilder : public ServerComponent
    {
      
    private:
        
        /*
         * TODO: Right now a Pseudo Player Event is just an std::pair.
         * This is bad because the PlayerEventType is accessed through .first
         * and the values vector<string> is accessed through .second.
         * Obviously this requires the maintainer to memorize the implementation of
         * the Pseudo Player Event.
         *
         * Better would be to make a PseudoPlayerEvent class that has accessors like
         * .getPlayerEventType and .getValues respectively.
         */
        std::pair<PlayerEventType, std::vector<std::string>> pseudoPlayerEvent;
        
    public:
        
        PlayerEventBuilder (std::pair<PlayerEventType, std::vector<std::string>> pseudoPlayerEvent);
        
        IPlayerEvent build ();
        
    };
    
}

#endif /* PlayerEventBuilder_hpp */
