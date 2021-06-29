#include "pch.h"
#include "Player.h"
#include "EnhancePowerCard.h"


EnhancePowerCard::EnhancePowerCard()
{
	this->setType("EnhancePowerCard");
	this->setName("EnhancePowerCard");
}

void EnhancePowerCard::action(Player* currentPlayer, Player* enemyPlayer)
{
	int powerCardIncreaseCount = 0;
	
	for (Card* element : currentPlayer->getBoard())
	{
		if(element->getName() == "Power Card Increase")
		{
			++powerCardIncreaseCount;
		}
		
	}

	currentPlayer->setPower(currentPlayer->getPower() + powerCardIncreaseCount);
}


EnhancePowerCard::~EnhancePowerCard()
{
}
