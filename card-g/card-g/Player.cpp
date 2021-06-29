#include "pch.h"
#include "Player.h"


Player::Player()
{
	power = 0;
}

std::string Player::getName()
{
	return this->name;
}

void Player::setName(std::string name)
{
	this->name = name;
}

int Player::getPower() const
{
	return power;
}

void Player::setPower(int power)
{
	this->power = power;
}

std::vector<Card*>& Player::getHand()
{
	return hand;
}

void Player::setHand(std::vector<Card*> cards)
{
	hand = cards;
}

std::vector<Card*> Player::getBoard() const
{
	return board.getBoard();
}

void Player::setBoard(Board board)
{
	this->board = board;
}

Board Player::getBoardObj()
{
	return this->board;
}

Player::~Player()
{
}
