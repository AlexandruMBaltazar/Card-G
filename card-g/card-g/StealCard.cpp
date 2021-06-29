#include "pch.h"
#include "Player.h"
#include "StealCard.h"
#include "PowerCardIncrease.h"


StealCard::StealCard()
{
	this->setType("Steal Card");
	this->setName("Steal Card");
}

// This is the actual implementation of the action method inherited from the Card interface
void StealCard::action(Player* currentPlayer, Player* enemyPlayer)
{
	//If the enemy hand is empty than increase the power by 1 else steal the card
	if(enemyPlayer->getHand().empty())
	{
		//Our steal card will take the role of an increase power card with a power level 1
		Card* powerCard = new PowerCardIncrease(1);

		//We put this card on the board as being played
		currentPlayer->getBoard().push_back(powerCard);

		//We are calling the action method of the powerIncreaseCard to increase the power level by 1
		powerCard->action(currentPlayer, enemyPlayer);

	}
	else
	{
		//We are getting the current card in the player hand
		std::vector<Card*> currentPlayerHand = currentPlayer->getHand();

		/*
		 * We are going to steal cards randomly so we need a random index associated with the cards
		 * in the enemy player hand.
		 */
		int randomIndex = rand() % enemyPlayer->getHand().size();

		//We are getting the stolen car from the enemy hand using the index generated above
		Card* stoledCard = enemyPlayer->getHand()[randomIndex];

		//We put the stolen card in the current player hand
		currentPlayer->getHand().push_back(stoledCard);

		//We erase the stolen card from the enemy player hand
		enemyPlayer->getHand().erase(enemyPlayer->getHand().begin() + randomIndex);
	}

	

}


StealCard::~StealCard()
{
}
