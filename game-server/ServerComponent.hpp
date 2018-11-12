//
//  ServerComponent.hpp
//  RedStarDungeonPartyGameServer
//
//  Created by Bob Desaunois on 05/11/2018.
//  Copyright © 2018 Bob Desaunois. All rights reserved.
//

#ifndef ServerComponent_hpp
#define ServerComponent_hpp

#include <string>
#include <iostream>

namespace OpenWorldGameServer
{
    
    class ServerComponent
    {
        
    public:
        
        virtual ~ServerComponent () = default;
        void log (std::string message);
        
    };
    
}

#endif /* ServerComponent_hpp */
