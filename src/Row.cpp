#include "row.h"

Row::Row(Color color)
    : color(color)
    , direction(UP)
    , status(UNLOCKED)
    , min_crosses(6) // = 5 + 1 (extra cross in beginning of vector)
    , crosses(1)
{
    direction = (color == RED || color == YELLOW) ? UP : DOWN;
    crosses[0] = (direction) ? 1 : 13;
}

Row::~Row()
{}

bool Row::CrossNumber(int num)
{
    if (CanCross(num))
    {
        crosses.push_back(num);
        if (direction == UP && num == 12)
            GetBonus();
        if (direction == DOWN && num == 2)
            GetBonus();
        return true;
    }
    return false;
}

void Row::LockRowOut()
{
    status = LOCKED;
}

void Row::GetBonus()
{
    crosses.push_back(100);
    LockRowOut();
}

Row::Lock Row::GetStatus()
{
    return status;
}

bool Row::CanCross(int num)
{   
    if(status == LOCKED)
        return false;
    if(num < 1 || num > 13)
        return false;
    if (direction == UP)
    {
        if(num == 12)
            return (crosses.size() >= (min_crosses)) && (num > crosses.back());
        return (num > crosses.back());
    }
    if (direction == DOWN)
    {
        if(num == 2)
            return (crosses.size() >= (min_crosses)) && (num < crosses.back());
        return (num < crosses.back());
    }
    return false;
}

std::string_view Row::GetColorName()
{
    switch (color)
    {
    case RED:       return "Red";
    case YELLOW:    return "Yellow";
    case GREEN:     return "Green";
    case BLUE:      return "Blue";
    default:        return "???";
    }
}

std::optional<Row::Color> Row::GetColorFromString(std::string_view sv)
{
    if (sv == "red")        return RED;
    if (sv == "yellow")     return YELLOW;
    if (sv == "green")      return GREEN;
    if (sv == "blue")       return BLUE;
    return {};
}

int Row::GetCrosses()
{
    return static_cast<int>(crosses.size()) - 1 ;
}

void Row::PrintRow()
{
    std::cout << GetColorName() << '\t';
    std::vector<int> heads_up{2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    if (direction == UP)
    {
        for (int num{2}; num <= 12; ++num)
        {
            if (std::find(crosses.begin(), crosses.end(), num) != crosses.end())
                std::cout << std::to_string(num) << " X" << '\t';
            else
                std::cout << std::to_string(num) << '\t';
        }
    }
    else if (direction == DOWN)
    {
        for (int num{12}; num >= 2; --num)
        {
            if (std::find(crosses.begin(), crosses.end(), num) != crosses.end())
                std::cout << num << " X" << '\t';
            else
                std::cout << num << '\t';
        }
    }
    
    if (crosses.back() == 100)
        std::cout << "Lock X" << std::endl;
    else
        std::cout << "Lock" << std::endl;
}   
