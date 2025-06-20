#include "Game.h"

Game::Game()
    : players()
    , numPlayers(0)
    , turnNumber(1)
    , playerTurn(0)
    , dices()
    , locks(0)
    , possibilities()
{}

Game::~Game()
{}

bool Game::SetPlayers(int num)
{
    if (num < 2 || num > 5)
    {
        std::cout << "Number of Players: 2 to 5" << '\n';
        return false;
    }
    for (int i{0}; i < num; ++i)
    {   
        Player player(i);
        players.push_back(player);
    }
    numPlayers = num;
    return true;
}

void Game::StartGame()
{   
    while (!GameOver())
    {   
        Turn turn{InitTurn()};

        MidTurn(turn);

        EndTurn();
    } 
    
}

Turn Game::InitTurn()
{   
    std::cout << "\nTURN " << turnNumber << '\n';
    Turn turn(turnNumber, numPlayers, dices.PossibleNumbers(dices.RollAllDice()));
    SetPlayersTurn(turn.GetActiveNumber());
    ShowCards();
    return turn;
}

void Game::MidTurn(Turn& turn)
{   
    size_t active{static_cast<size_t>(turn.GetActiveNumber())};
    bool usedWhite{turn.UseWhiteDice(players[active])};
    bool usedColorful{turn.UseColorfulDice(players[active])};
    if(!usedWhite && !usedColorful)
        players[active].ApplyPenalty();
    for (auto idx : turn.GetPassiveOrder())
        turn.UseWhiteDice(players[static_cast<size_t>(idx)]);
}

bool Game::EndTurn()
{   
    for (auto& player : players)
    {   
        auto locks{player.GetLocks()};
        for (uint8_t i{0}; i < 4; ++i)
        {
            if(locks[i])
                dices.RemoveDice(static_cast<Dice::Color>(i));
            break;
        }
    }
    turnNumber++;
    return true;
}

void Game::ShowCards()
{
    for (Player player : players)
    {   
        std::cout << "PLAYER " << player.GetPlayerNumber() + 1;
        if (player.IsTurn())
            std::cout << " TURN";
        std::cout << '\n';
        player.ShowCard();
    }
}

void Game::SetPlayersTurn(int activeNumber)
{
    for (auto& player : players)
        player.SetTurn(Player::NOT_TURN);
    players[static_cast<std::size_t>(activeNumber)].SetTurn(Player::IN_TURN);
}

void Game::PrintPoints()
{   
    std::cout << "Points: " << '\n';
    for (Player player : players)
    {
        std::cout << "Player "<< player.GetPlayerNumber() + 1 << ": \t" << player.GetPoints() << " points\n";
    }
    std::cout << std::endl;
}

bool Game::GameOver()
{   
    bool over{false};
    for (auto& player : players)
    {
        if (player.GetPenalties() >= 4)
        {
            over = true;
            break;
        }
    }
    if (locks > 1 || turnNumber > 6)
    {
        std::cout << "GAME OVER" << '\n';
        PrintPoints();
        return true;
    }
    return false;
}

void Game::ClearConsole() {
    system("cls");
}


