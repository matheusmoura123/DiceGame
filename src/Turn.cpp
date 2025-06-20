#include "Turn.h"

Turn::Turn(int turnNumber, int numPlayers, std::vector<std::vector<int>> possibleNumbers)
    : numPlayers(numPlayers) 
    , activePlayerNumber((turnNumber%numPlayers) ? turnNumber%numPlayers-1 : numPlayers-1)
    , passivePlayersOrder(SortRestPlayers())
    , possibleNumbers(possibleNumbers)
{}

Turn::~Turn()
{}

std::vector<int> Turn::SortRestPlayers()
{
    std::vector<int> sortedRestPlayers{};
    for (int i{0}; i < numPlayers-1; ++i)
    {
        sortedRestPlayers.push_back((i+activePlayerNumber+1)%numPlayers);
    }
    return sortedRestPlayers;
}

int Turn::GetActiveNumber()
{
    return activePlayerNumber;
}

std::vector<int> Turn::GetPassiveOrder()
{
    return passivePlayersOrder;
}

bool Turn::UseWhiteDice(Player& player)
{
    return UseDice(player, "WHITE");
}

bool Turn::UseColorfulDice(Player& player)
{
    return UseDice(player, "COLORFUL");
}

bool Turn::UseDice(Player& player, const std::string dice)
{   
    while (1)
    {
        auto [color, number] = GetInput(dice);
        if (number == 0)
        {
            std::cout << '\n';
            return false;
        }
        if(!player.MakeCross(color, number))
        {
            std::cout << "Can't Cross that\n";
            continue;
        }
        break;
    }
    return true;
}

std::pair<Row::Color, int> Turn::GetInput(const std::string dice)
{
    std::optional<Row::Color> color;
    int number{0};
    bool correct{false};
    while (!correct)
    {
        std::cout << dice <<" DICES (row_color number) or (no 0): ";
        std::string color_str;
        std::string number_str;
        std::cin >> color_str >> number_str;
        if (color_str == "no")
        {
            return {*color, number};
        }
        {
            Row row(Row::RED);
            color = row.GetColorFromString(color_str);
        }
        if (!color)
        {
            std::cout << "Invalid color\n";
            continue;
        }
        if (!isNumberPossible(*color, number_str, dice))
        {
            std::cout << "Invalid number\n";
            continue;
        }
        number = std::stoi(number_str);
        correct = true;
    }
    return {*color, number};
}



bool Turn::isNumberPossible(Row::Color color, const std::string& num_str, const std::string dice)
{   
    try {
        int num{};
        size_t pos;
        std::stoi(num_str, &pos);
        if(pos == num_str.length())
        {
            num = std::stoi(num_str);
            if (dice == "WHITE")
            {
                return num == possibleNumbers[4][0];
            }
            if (dice == "COLORFUL")
            {
                return (std::find(possibleNumbers[color].begin(), possibleNumbers[color].end(), num) != possibleNumbers[color].end());
            }
            return false;
            
        }
    } catch (...) {
        return false;
    }
    return false;
}
