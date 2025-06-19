# include "player.h"

Player::Player(int playerNumber)
    : number(playerNumber)
    , points(0)
    , turn(NOT_TURN)
    , card()
{}

Player::~Player()
{}

int Player::GetPlayerNumber()
{
    return number;
}

void Player::SetTurn(Turn isTurn)
{
    turn = isTurn;
}

bool Player::IsTurn()
{
    return turn;
}

int Player::GetPoints()
{   
    points = card.GetPoints();
    return points;
}

int Player::GetPenalties()
{   
    return card.GetPenalties();
}

void Player::ApplyPenalty()
{   
    card.ApplyPenalty();
}

void Player::ShowCard()
{
    card.ShowCard();
}

bool Player::MakeCross(Row::Color color, int num)
{
    return card.CrossRow(color, num);
}


