#include "DiceSet.h"

DiceSet::DiceSet()
    : dices({Dice::WHITE_1, 
        Dice::WHITE_2, 
        Dice::RED, 
        Dice::YELLOW, 
        Dice::GREEN, 
        Dice::BLUE})
    , diceRemoved(false)
{}

DiceSet::~DiceSet()
{}

std::vector<int> DiceSet::RollAllDice()
{
    // Roll all 6 dice and return in a vector
    // 2 first white, red, yellow, green, blue
    // if dice is excluded, returns 0 for that dice
    std::vector<int> result {};
    for (uint8_t i{0}; i <= 5; ++i)
    {
        result.push_back(dices[i].Roll());
    }
    ShowThrow(result);
    return result;
}

std::vector<std::vector<int>> DiceSet::PossibleNumbers(std::vector<int> diceThrow)
{
    std::vector<std::vector<int>> possibilities(4, {diceThrow[0]+diceThrow[1]});
    for (uint8_t i = 2; i < 6; ++i)
    {
        if (diceThrow[i])
        {
            possibilities[i-2].push_back(diceThrow[0]+diceThrow[i]);
            if (diceThrow[0] != diceThrow[1])
            {
                possibilities[i-2].push_back(diceThrow[1]+diceThrow[i]);
            }
        }
    }
    return possibilities;
}

bool DiceSet::RemoveDice(Dice::Color color)
{   
    if (diceRemoved)
    {
        std::cout << "One dice already removed" << '\n';
        return false;
    }
    if (color < Dice::RED || color > Dice::BLUE)
    {
        std::cout << "Incorrect color" << '\n';
        return false;
    }
    diceRemoved=dices[color].RemoveFromGame();
    return true;
}

void DiceSet::ShowThrow(std::vector<int> diceThrow)
{
    std::vector<std::string> colors = {"White", "White", "Red", "Yellow", "Green", "Blue"};
    for (const std::string& color : colors) {
        std::cout << color << "\t";
    }
    std::cout << '\n';

    std::string out;
    for (int num : diceThrow) {
        out = (num) ? std::to_string(num) : "OUT";
        std::cout << out << "\t";
    }
    std::cout << "\n\n";
}
