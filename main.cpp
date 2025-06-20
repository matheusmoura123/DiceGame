#include <iostream>

#include "Game.h"

int main()
{   
    Game game;
    // int numPlayers;
    // std::cout << "Number of Players: ";
    // std::cin >> numPlayers;
    game.SetPlayers(2);
    game.StartGame();
    
    return 0;
}
