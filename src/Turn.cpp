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

bool Turn::PlayWhiteDice(Player& player)
{   
    while (1)
    {
        auto [color, number] = GetInput("WHITE DICES (row_color number) or (no 0): ");
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

std::pair<Row::Color, int> Turn::GetInput(std::string msg)
{
    std::optional<Row::Color> color;
    int number{0};
    bool correct{false};
    while (!correct)
    {
        std::cout << msg;
        std::string color_str;
        std::string number_str;
        std::cin >> color_str >> number_str;
        if (color_str == "no")
        {
            return {*color, number};
        }
        color = getColorFromString(color_str);
        if (!color)
        {
            std::cout << "Invalid color\n";
            continue;
        }
        if (!isNumber(*color, number_str))
        {
            std::cout << "Invalid number\n";
            continue;
        }
        number = std::stoi(number_str);
        correct = true;
    }
    return {*color, number};
}

constexpr std::optional<Row::Color> Turn::getColorFromString(std::string_view sv)
{
    if (sv == "red")        return Row::RED;
    if (sv == "yellow")     return Row::YELLOW;
    if (sv == "green")      return Row::GREEN;
    if (sv == "blue")       return Row::BLUE;
    return {};
}

bool Turn::isNumber(Row::Color color, const std::string& num_str)
{   
    try {
        int num{};
        size_t pos;
        std::stoi(num_str, &pos);
        if(pos == num_str.length())
        {
            num = std::stoi(num_str);
            return (std::find(possibleNumbers[color].begin(), possibleNumbers[color].end(), num) != possibleNumbers[color].end());
        }
    } catch (...) {
        return false;
    }
    return false;
}

// Write check for possible
bool Turn::
