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
    void InitTurn();
    void AskPlayers();
    void AskPlayer(int idx);
    bool EndTurn();
    void ShowCards();
    void SetPlayersTurn();
    void PrintPoints();
    bool GameOver();
    void ClearConsole();

};
