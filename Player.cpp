// Player class.
// Gets and stores data related to the player.
// All functions are get and set methods for private variables.

#include "Player.h"

//============================================================

Player::Player()
{
}

//============================================================

std::string Player::getName()
{
	return _name;
}

//============================================================

void Player::setName(std::string name)
{
	_name = name;
}

//============================================================

char Player::getToken()
{
	return _token;
}

//============================================================

void Player::setToken(char token)
{
	_token = token;
}

//============================================================