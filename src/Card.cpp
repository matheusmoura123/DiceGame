#include "card.h"

Card::Card()
    : rows({Row::RED, Row::YELLOW, Row::GREEN, Row::BLUE})
    , penalties(0)
{}

Card::~Card()
{}

void Card::ShowCard()
{
    for (Row row : rows)
        row.PrintRow();
    std::cout << "Penalties" << '\t';
    for (int i{0}; i < penalties; ++i)
        std::cout << "X ";
    std::cout << '\n' << std::endl; 
}

bool Card::MakeCross(Row::Color color, int num)
{
    if(rows[color].CrossNumber(num))
    {
        // ShowCard();
        return true;
    }
    return false;
}

bool Card::LockRow(Row::Color color)
{
    rows[color].LockRowOut();
    return true;
}

std::vector<int> Card::GetLocks()
{
    std::vector<int>locks{};
    for(auto row : rows)
    {
        locks.push_back(row.GetStatus());
    }
    return locks;
}

int Card::GetPoints()
{
    int points{0};
    int crosses{0};
    for (Row row : rows)
    {   
        crosses = row.GetCrosses();
        points += (crosses+1)*crosses/2;
    }
    points -= penalties*5;
    return points;
}

int Card::GetPenalties()
{
    return penalties;
}

void Card::ApplyPenalty()
{
    penalties++;
}
