#include "pch.h"
#include "Player.h"
#include "ShieldCard.h"


ShieldCard::ShieldCard()
{
	this->setType("Thief Catcher Card");
	this->setName("Thief Catcher Card");
}

void ShieldCard::action(Player* currentPlayer, Player* enemyPlayer)
{
	if (enemyPlayer->getBoardObj().getPlayedCard()->getName() == "Power Card Decrease")
	{
		
	}
		
}


ShieldCard::~ShieldCard()
{
}
