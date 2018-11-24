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
    this->playerEventBuffer    = *new std::vector<PlayerEvent>;
    
    status = this->clientSocket.bind (PORT);
    
    if (status != sf::Socket::Status::Done)
    {
        
        this->log ("An incoming connection could not be established :(");
        return;
        
    }
    
    this->running = 1;
    this->log ("Server up and running.");
    this->log ("Good luck! :)");
    
    this->networkingServerLogic = *new NetworkingServerLogic ();
    std::thread logicThread
    (
        &NetworkingServerLogic::loop
    ,   this->networkingServerLogic
    );
    
    while (this->running)
        this->listen ();
        
}

std::vector<OpenWorldGameServer::PlayerConnection>&
OpenWorldGameServer::NetworkingServer::getPlayerConnectionPool
    ()
{
    
    return playerConnectionPool;
    
};

/*
 * TODO: Thread player connections and let them handle everything themselves.
 * Currently this listen function serves as the only point
 * where the server listens to the client.
 * So every connected client goes through here.
 * In the future it would be wise to make connections threaded
 * and let them concurrently listen for events. :)
 */
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
    
    
    auto playerEvent = this->networkingProtocol.parse ((std::string) data);

    // Add event to eventbuffer which will get handled
    // somewhere in NetworkingServerLogic.cpp
    this->playerEventBuffer.push_back (playerEvent);

};

std::string
OpenWorldGameServer::NetworkingServer::generatePlayerID
    ()
{
    
    boost::uuids::uuid playerUUID = boost::uuids::random_generator ()();
    return (std::string) boost::uuids::to_string (playerUUID);
    
};
