#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Card.h"

class Player
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

    int GetPoints();
    int GetPenalties();
    void ApplyPenalty();
    void ShowCard();
    bool MakeCross(Row::Color color, int num);

private:
};
