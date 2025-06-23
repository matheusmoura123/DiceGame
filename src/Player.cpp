# include "player.h"

Player::Player(int playerNumber)
    : number(playerNumber)
    , points(0)
    , turn(NOT_TURN)
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
