#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Row.h"

class Card
{
public:
    Card();

public:
    ~Card();

private: 
    std::vector<Row> rows;
    int penalties;

public:
    void ShowCard();
    bool MakeCross(Row::Color color, int num);
    bool LockRow(Row::Color color);
    std::vector<int> GetLocks();
    int GetPoints();
    int GetPenalties();
    void ApplyPenalty();

};
