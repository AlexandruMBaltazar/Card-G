#include "pch.h"
#include "Player.h"
#include "PowerCardDecrease.h"
#include <sstream>

PowerCardDecrease::PowerCardDecrease(int minPower, int maxPower): PowerCard(minPower, maxPower)
{
	std::stringstream ss;

	ss << "Power Card Decrease : " << powerLevel;

	this->setType(ss.str());

	this->setName("Power Card Decrease");
}

// This is the actual implementation of the action method inherited from the Card interface
void PowerCardDecrease::action(Player* currentPlayer, Player* enemyPlayer)
{
	std::cout << "Decrease Power" << ":" << "Level " << powerLevel << std::endl;

	//We are getting the power of the enemy player
	int power = enemyPlayer->getPower();

	//This if statement will check if the power level is not already zero if it is there is no point decreasing it further
	if(power != 0)
	{
		//We decrease the current power by the power level of this card
		power = power - this->powerLevel;
	
		if(power > 0)
		{
			enemyPlayer->setPower(power);
		}
		else
		{
			enemyPlayer->setPower(0);
		}
	}

	
}

PowerCardDecrease::~PowerCardDecrease()
{
}
