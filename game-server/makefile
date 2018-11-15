game-server: main.o GameServer.o NetworkingProtocol.o NetworkingServer.o PlayerConnection.o PlayerEvent.o PlayerEventTypeResolver.o PlayerPosition.o ServerComponent.o
    g++ -o game-server main.o GameServer.o NetworkingProtocol.o NetworkingServer.o PlayerConnection.o PlayerEvent.o PlayerEventTypeResolver.o PlayerPosition.o ServerComponent.o -lsfml-network

main.o: main.cpp
    g++ -c main.cpp

GameServer.o: GameServer.hpp GameServer.cpp
    g++ -c GameServer.hpp GameServer.cpp

NetworkingProtocol.o: NetworkingProtocol.hpp NetworkingProtocol.cpp
    g++ -c NetworkingProtocol.hpp NetworkingProtocol.cpp

NetworkingServer.o: NetworkingServer.hpp NetworkingServer.cpp
    g++ -c NetworkingServer.hpp NetworkingServer.cpp

PlayerConnection.o: PlayerConnection.hpp PlayerConnection.cpp
    g++ -c PlayerConnection.hpp PlayerConnection.cpp

PlayerEvent.o: PlayerEvent.hpp PlayerEvent.cpp
    g++ -c PlayerEvent.hpp PlayerEvent.cpp

PlayerEventTypeResolver.o: PlayerEventTypeResolver.hpp PlayerEventTypeResolver.cpp
    g++ -c PlayerEventTypeResolver.hpp PlayerEventTypeResolver.cpp

PlayerPosition.o: PlayerPosition.hpp PlayerPosition.cpp
    g++ -c PlayerPosition.hpp PlayerPosition.cpp

ServerComponent.o: ServerComponent.hpp ServerComponent.cpp
    g++ -c ServerComponent.hpp ServerComponent.cpp

clean:
    rm -rf game-server *.o *.gch
