#  Open World Game Server

Open World Game Server for a game I'm building with friends.
It's built to run on OS X, with compatibility for Linux.

-----------------------------------------------------------------------------

## Dependencies (OS X)

- SFML (`<SFML/Network.hpp>`, https://www.sfml-dev.org/tutorials/2.5/start-osx.php)
- boost (`brew install boost`)

-----------------------------------------------------------------------------

## Dependencies (Linux)

- SFML (`<SFML/Network.hpp>`, `sudo apt-get install libsfml-dev`)
- boost (`sudo apt-get install libboost-all-dev`) This version might be out of date...
- add `-lsfml-network` flag to makefile
