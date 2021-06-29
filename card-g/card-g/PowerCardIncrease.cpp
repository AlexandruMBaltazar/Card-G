#include "pch.h"
#include "Player.h"
#include "PowerCardIncrease.h"
#include <sstream>


PowerCardIncrease::PowerCardIncrease(int power) : PowerCard(power)
{
	std::stringstream ss;

	ss << "Power Card Increase : " << powerLevel;

	this->setType(ss.str());

	this->setName("Power Card Increase");
}

PowerCardIncrease::PowerCardIncrease(int minPower, int maxPower): PowerCard(minPower, maxPower)
{
	std::stringstream ss;

	ss << "Power Card Increase : " << powerLevel;

	this->setType(ss.str());

	this->setName("Power Card Increase");
}

// This is the actual implementation of the action method inherited from the Card interface
void PowerCardIncrease::action(Player* currentPlayer, Player* enemyPlayer)
{
	std::cout << "Increase Power" << ":" << "Level " << powerLevel << std::endl;

	//We are getting the current power of the player
	int power = currentPlayer->getPower();

	//We are increasing it by the power level of this card
	power = power + this->powerLevel;

	//We are setting up a new power level for the player
	currentPlayer->setPower(power);
}


PowerCardIncrease::~PowerCardIncrease()
{
}
