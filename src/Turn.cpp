#include "Turn.h"

Turn::Turn(int turnNumber, std::vector<Player>& players, std::vector<std::vector<int>> possibleNumbers)
    : numPlayers(static_cast<int>(players.size())) 
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

void Turn::PlayWhiteDice(Player& player)
{   
    bool correct{false};
    while (!correct)
    {
        auto [color, number] = GetInput("Use white dices (row_color [SPACE] number) or (no 0): ");
        if (number == 0)
        {
            // Don't cross function
            correct =true;
        }
        if(!player.MakeCross(color, number))
        {
            std::cout << "Can't Cross that\n";
            continue;
        }
        std::cout << '\n';
        correct = true;
    }
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
        if (!isPossibleNumber(*color, number_str))
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

bool Turn::isPossibleNumber(Row::Color color, const std::string& num_str)
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
