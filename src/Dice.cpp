#include "dice.h"

Dice::Dice(Color color)
    : color(color)
    , status(IN_GAME)
{}

Dice::~Dice()
{}

bool Dice::RemoveFromGame()
{
    if (status == IN_GAME)
    {
        status = OUT_GAME;
        return true;
    }
    return false;
}

int Dice::Roll()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 6);
    return (status) ? dist(gen) : 0;
}
