#include "Turn.h"

Turn::Turn(int turnNumber, std::vector<Player>& players, std::vector<int> diceResult)
    : numPlayers(static_cast<int>(players.size())) 
    , activeNumber((turnNumber%numPlayers) ? turnNumber%numPlayers-1 : numPlayers-1)
    , activePlayer(players[static_cast<size_t>(activeNumber)])
    , restPlayers(SortRestPlayers(players))
    , diceResult(diceResult)
{}

Turn::~Turn()
{}

std::vector<Player> Turn::SortRestPlayers(const std::vector<Player> players)
{
    std::vector<Player> sortedRestPlayers{};
    for (int i{0}; i < numPlayers-1; ++i)
    {
        sortedRestPlayers.push_back(players[static_cast<size_t>((i-1+activeNumber)%numPlayers)]);
    }
    return sortedRestPlayers;
}
