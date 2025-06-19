#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Player.h"

class Turn
{
public:
    Turn(int turnNumber, std::vector<Player>& players, std::vector<int> diceResult);

public:
    ~Turn();

private:
    int numPlayers;
    int activeNumber;
    Player activePlayer;
    std::vector<Player> restPlayers;
    std::vector<int> diceResult;

public:
    void PlayWhiteDice(Player& player);
    void PlayColoredDice(Player& player);

private:
    std::vector<Player> SortRestPlayers(const std::vector<Player> Players);

};
