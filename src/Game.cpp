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
        Turn turn(turnNumber, players, dices.RollAllDice());
        ShowCards();
        std::cin.get();
        turnNumber++;
    } 
    
}

void Game::InitTurn()
{   
    std::cout << "TURN " << turnNumber << '\n';
    SetPlayersTurn();

    possibilities = dices.PossibleNumbers(dices.RollAllDice());
    ShowCards();
}

void Game::AskPlayers()
{
    for (int i{0}; i < numPlayers; ++i)
    {
        AskPlayer((i+playerTurn)%numPlayers);
    }
}

void Game::AskPlayer(int idx)
{   
    Player* player = &players[static_cast<std::size_t>(idx)];
    int color;
    int number;
    if (player->IsTurn())
    {
        std::cout << "Use white dices (row_number[SPACE]number): ";
        std::cin >> color >> number;
        player->MakeCross(static_cast<Row::Color>(color), number);
        std::cout << '\n';
    }
}

bool Game::EndTurn()
{
    turnNumber++;

    return true;
}

void Game::ShowCards()
{
    for (Player player : players)
    {   
        std::cout << "Player " << player.GetPlayerNumber() + 1;
        if (player.IsTurn())
            std::cout << " TURN";
        std::cout << '\n';
        player.ShowCard();
        std::cout << '\n';
    }
}

void Game::SetPlayersTurn()
{
    for (auto& player : players)
        player.SetTurn(Player::NOT_TURN);

    playerTurn = (turnNumber%numPlayers) ? turnNumber%numPlayers-1 : numPlayers-1;
    players[static_cast<std::size_t>(playerTurn)].SetTurn(Player::IN_TURN);
}

void Game::PrintPoints()
{   
    std::cout << "Points: " << '\n';
    for (Player player : players)
    {
        std::cout << "Player "<< player.GetPlayerNumber() + 1 << ": \t" << player.GetPoints() << " points\n";
    }
}

bool Game::GameOver()
{
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


