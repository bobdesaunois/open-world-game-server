//
//  NetworkingServer.cpp
//  RedStarDungeonPartyGameServer
//
//  Created by Bob Desaunois on 05/11/2018.
//  Copyright © 2018 Bob Desaunois. All rights reserved.
//

#include "NetworkingServer.hpp"

OpenWorldGameServer::NetworkingServer::NetworkingServer ()
{
  
    this->log ("Booting up NetworkingServer...");
    
    
    sf::Socket::Status status;
    
    status = this->clientSocket.bind (PORT);
    
    if (status != sf::Socket::Status::Done)
    {
        
        this->log ("An incoming connection could not be established :(");
        return;
        
    }
    
    this->log ("Server up and running.");
    this->log ("Good luck! :)");
    
    this->listen ();
        
}

void
OpenWorldGameServer::NetworkingServer::listen ()
{
    
    sf::IpAddress sender;
    unsigned short port;
    char data[100];
    std::size_t received;
    
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
        
        this->log ("A new player has connected :)");
        this->log ("Details:");
        std::cout
        << "ip: "       << playerEvent.getValue (2)
        << "username: " << playerEvent.getValue (3)
        << std::endl;
        
    }
    
};


