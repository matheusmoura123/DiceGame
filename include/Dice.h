#pragma once

#include <random>

class Dice
{
public:
    enum Color {
        WHITE_1,
        WHITE_2,
        RED, 
        YELLOW, 
        GREEN, 
        BLUE,
    };

    enum InGame {
        OUT_GAME,
        IN_GAME,
    };

public:
    Dice(Color color);

public:
    ~Dice();

private:
    Color color;
    InGame status;

public:
    bool RemoveFromGame();
    int Roll();
};
