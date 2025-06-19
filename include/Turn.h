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
    Turn(int turnNumber, std::vector<Player>& players, std::vector<std::vector<int>> possibleNumbers);

public:
    ~Turn();

private:
    int numPlayers;
    int activePlayerNumber;
    std::vector<int> passivePlayersOrder;
    std::vector<std::vector<int>> possibleNumbers;

public:
    void PlayWhiteDice(Player& player);
    void PlayColoredDice(Player& player);

private:
    std::vector<int> SortRestPlayers();
    constexpr std::optional<Row::Color> getColorFromString(std::string_view sv);
    bool isPossibleNumber(Row::Color color, const std::string& num);
    std::pair<Row::Color, int> GetInput(std::string msg);
};
