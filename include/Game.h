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
    int removedDice;
    std::vector<std::vector<int>> possibilities;

public:
    void StartGame();
  
private:
    void AskNumPlayers();
    void SetPlayers(int num);
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
