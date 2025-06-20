#pragma once

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "DiceSet.h"
#include "Player.h"
#include "Turn.h"

class Game
{
public:
    Game();

public:
    ~Game();

private:
    std::vector<Player> players;
    int numPlayers;
    int turnNumber;
    int playerTurn;
    DiceSet dices;
    int locks;
    std::vector<std::vector<int>> possibilities;

public:
    bool SetPlayers(int num);
    void StartGame();
  
private:
    Turn InitTurn();
    void MidTurn(Turn& turn);
    bool EndTurn();
    void ShowCards();
    void SetPlayersTurn(int activeNumber);
    void PrintPoints();
    bool GameOver();
    void ShowPlayer(Player& player);
    void ClearConsole();

};
