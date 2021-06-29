#include "pch.h"
#include "Player.h"
#include "ThiefCatcherCard.h"



#include <algorithm>
#include <chrono>
#include <iostream>
#include <list>
#include <thread>


ThiefCatcherCard::ThiefCatcherCard()
{
	this->setType("Thief Catcher Card");
	this->setName("Thief Catcher Card");
}

bool isStealCard(Card* card) { return (card->getType() == "Steal Card") ; }

void ThiefCatcherCard::action(Player* currentPlayer, Player* enemyPlayer)
{


	
	for(int i = 0; i < enemyPlayer->getHand().size(); i++)
	{

		if(enemyPlayer->getHand()[i]->getType() == "Steal Card")
		{
			enemyPlayer->getHand().erase(enemyPlayer->getHand().begin() + i);
			break;
		}
	
	}

	
}


ThiefCatcherCard::~ThiefCatcherCard()
{
}
