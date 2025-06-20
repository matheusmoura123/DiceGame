#pragma once

#include <iostream>
#include <optional>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

#include "Player.h"

class Turn
{
public:
    Turn(int turnNumber, int numPlayers, std::vector<std::vector<int>> possibleNumbers);

public:
    ~Turn();

private:
    int numPlayers;
    int activePlayerNumber;
    std::vector<int> passivePlayersOrder;
    std::vector<std::vector<int>> possibleNumbers;

public:
    int GetActiveNumber();
    std::vector<int> GetPassiveOrder();
    bool UseWhiteDice(Player& player);
    bool UseColorfulDice(Player& player);
    
private:
    std::vector<int> SortRestPlayers();
    bool UseDice(Player& player, const std::string dice);
    bool isNumberPossible(Row::Color color, const std::string& num_str, const std::string dice);
    std::pair<Row::Color, int> GetInput(const std::string dice);
};
