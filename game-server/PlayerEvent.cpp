//
//  PlayerEvent.cpp
//  game-server
//
//  Created by Bob Desaunois on 12/11/2018.
//  Copyright © 2018 Bob Desaunois. All rights reserved.
//

#include "PlayerEvent.hpp"

template<class T>
OpenWorldGameServer::PlayerEvent<T>::PlayerEvent
    (std::vector<std::string> values)
{
    
    this->event = *new T (values);
    
};

template<class T>
std::string
OpenWorldGameServer::PlayerEvent<T>::getValue
    (int index)
{
    
    return this->values.at (index);
    
};

template<class T>
OpenWorldGameServer::PlayerEventType
OpenWorldGameServer::PlayerEvent<T>::getType
    ()
{
    
    return this->type;
    
};

template<class T>
T*
OpenWorldGameServer::PlayerEvent<T>::getEvent
    ()
{
    
    return &this->event;
    
};
