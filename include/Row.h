#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

class Row
{
public:
    enum Color {
        RED, 
        YELLOW, 
        GREEN, 
        BLUE,
    };

    enum Lock {
        UNLOCKED,
        LOCKED,
    };

    enum Direction {
        DOWN,
        UP,
    };

public:
    Row(Color color);

public:
    ~Row();

private:
    Color color;
    Direction direction;
    Lock status;
    uint8_t min_crosses;
    std::vector<int> crosses;

public:
    bool CrossNumber(int num);
    void LockRowOut();
    constexpr std::string_view GetColorName();
    void PrintRow();
    int GetCrosses();
    
private:
    void LockRowBonus();
    bool CanCross(int num);
};
