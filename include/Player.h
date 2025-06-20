#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Card.h"

class Player : public Card
{
public:
    enum Turn {
        NOT_TURN,
        IN_TURN,
    };

private:
    int number;
    int points;
    Turn turn;
    Card card;

public:
    Player(int playerNumber);

public:
    ~Player();

public:
    int GetPlayerNumber();
    void SetTurn(Turn isTurn);
    bool IsTurn();
};
