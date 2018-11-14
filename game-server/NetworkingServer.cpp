//
//  NetworkingServer.cpp
//  RedStarDungeonPartyGameServer
//
//  Created by Bob Desaunois on 05/11/2018.
//  Copyright © 2018 Bob Desaunois. All rights reserved.
//

#include "NetworkingServer.hpp"

OpenWorldGameServer::NetworkingServer::NetworkingServer
    ()
{
  
    this->log ("Booting up NetworkingServer...");
    
    sf::Socket::Status status;
    this->playerConnectionPool = *new std::vector<PlayerConnection>;
    
    status = this->clientSocket.bind (PORT);
    
    if (status != sf::Socket::Status::Done)
    {
        
        this->log ("An incoming connection could not be established :(");
        return;
        
    }
    
    this->running = 1;
    this->log ("Server up and running.");
    this->log ("Good luck! :)");
    
    while (this->running)
        this->listen ();
        
}

std::vector<OpenWorldGameServer::PlayerConnection>*
OpenWorldGameServer::NetworkingServer::getPlayerConnectionPool
    ()
{
    
    return &playerConnectionPool;
    
};

void
OpenWorldGameServer::NetworkingServer::listen
    ()
{
    
    sf::IpAddress  sender;
    unsigned short port;
    char           data[100];
    std::size_t    received;
    
    if
    (
        this->clientSocket.receive
            (data, 100, received, sender, port) != sf::Socket::Done
    )
    {
        
        this->log ("Could not receive message from Client");
        
    }
    
    
    PlayerEvent playerEvent = this->networkingProtocol.parse ((std::string) data);
    
    if (playerEvent.getType() == PlayerEventType::HELLO)
    {
        
        
        this->logNewConnection (playerEvent);
        this->handleNewConnection (playerEvent);
        
    }
    else
    {
        
        this->handleNewEvent (playerEvent);
        
    }
    
};

void
OpenWorldGameServer::NetworkingServer::logNewConnection
    (PlayerEvent helloEvent)
{
    
    this->log ("A new player has connected :)");
    this->log ("Details:");
    std::cout
    << "hostname: " << helloEvent.getValue (2) << std::endl
    << "username: " << helloEvent.getValue (3) << std::endl;
    
}

void
OpenWorldGameServer::NetworkingServer::handleNewConnection
    (PlayerEvent helloEvent)
{
    
    std::string hostname  = helloEvent.getValue (2);
    std::string username  = helloEvent.getValue (3);
    
    this->getPlayerConnectionPool ()
        ->push_back (*new PlayerConnection (hostname, username));
    
};

void
OpenWorldGameServer::NetworkingServer::handleNewEvent
    (PlayerEvent playerEvent)
{
    
    // implement me !
    
}
