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
//#include "HelloEvent.hpp"

namespace OpenWorldGameServer
{
    
    template<class T>
    class PlayerEventBuilder : public ServerComponent
    {
      
    private:
        
    public:
        
        T build ()
        {
            
            return *new T ();//values);
            
        };//std::vector<std::string> values);
        
//        static PlayerEventBuilder getInstance ();
        
    };
    
}

#endif /* PlayerEventBuilder_hpp */
