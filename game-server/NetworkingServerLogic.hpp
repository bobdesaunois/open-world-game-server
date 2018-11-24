//
//  NetworkingServerLogic.hpp
//  game-server
//
//  Created by Bob Desaunois on 24/11/2018.
//  Copyright © 2018 Bob Desaunois. All rights reserved.
//

#ifndef NetworkingServerLogic_hpp
#define NetworkingServerLogic_hpp

#include "ServerComponent.hpp"

namespace OpenWorldGameServer{
    
    class NetworkingServerLogic : public ServerComponent
    {
        
    private:
        
    public:
        
        void loop ();
        
    };
    
}

#endif /* NetworkingServerLogic_hpp */
