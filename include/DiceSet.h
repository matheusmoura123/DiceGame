#pragma once

#include <iostream>
#include <vector>

#include "Dice.h"

class DiceSet
{
public:
    DiceSet();

public:
    ~DiceSet();

private:
    std::vector<Dice> dices;
    bool diceRemoved;

public: 
    std::vector<int> RollAllDice();
    std::vector<std::vector<int>> PossibleNumbers(std::vector<int> diceThrow);
    bool RemoveDice(Dice::Color color);

private:
    void ShowThrow(std::vector<int> diceThrow);

};
