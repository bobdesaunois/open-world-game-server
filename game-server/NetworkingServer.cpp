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
    
    sf::IpAddress sender = "127.0.0.1";
    unsigned short port = PORT;
    char data[100];
    std::size_t received;
    
    if
    (
        this->clientSocket.receive
        (
            data
        ,   100
        ,   received
        ,   sender
        ,   port
        ) != sf::Socket::Done
    )
    {
        
        this->log ("Could not receive message from Client");
        
    }
    
    std::cout << (std::string) data
        << std::endl;
    
};


