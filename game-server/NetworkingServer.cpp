//
//  NetworkingServer.cpp
//  RedStarDungeonPartyGameServer
//
//  Created by Bob Desaunois on 05/11/2018.
//  Copyright © 2018 Bob Desaunois. All rights reserved.
//

#include "NetworkingServer.hpp"

RedStarDungeonParty::NetworkingServer::NetworkingServer ()
{
  
    this->log ("Booting up NetworkingServer...");
    
    sf::TcpListener listener;
    
    // bind the listener to a port
    if (listener.listen(1337) != sf::Socket::Done)
    {
        
        std::cout
            << "Could not bind listener to port!"
            << std::endl;
        
    }
    
    // accept a new connection
    sf::TcpSocket client;
    if (listener.accept(client) != sf::Socket::Done)
    {
        
        std::cout
            << "Could not accept new incoming connection :("
            << std::endl;
        
    }
    
    char data[100];
    std::size_t received;
    sf::UdpSocket socket;
    
    if (client.receive (data, 100, received) != sf::Socket::Done)
    {
        
        std::cout
            << "Dat kon ik niet ontavngen :("
            << std::endl;
        
    }
    
    std::cout << "Received: " << received << " bytes" << std::endl;
    std::cout << "I received this: " << (std::string) data << std::endl;
    
    const char* berichtAanRichard = "Bericht aan Richard terug, hoi Richard! Ik mis Ronald :(";
    if (client.send (berichtAanRichard, 100) != sf::Socket::Done)
    {
    
        std::cout << "Dat kon ik niet sturen :(" << std::endl;
        
    }

};
