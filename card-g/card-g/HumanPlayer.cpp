#include "pch.h"
#include "HumanPlayer.h"


HumanPlayer::HumanPlayer() :Player()
{
	setName("Human Player");
}


void HumanPlayer::selectCard(std::vector<Card*>& cardDeck, int index)
{
	this->deck = cardDeck;

	//This is a simple exception checking if the user picks a card that is out of bounds, doesn't exist
	if(index > cardDeck.size() - 1 || index < 0)
	{
		throw "Item out of range";
	}

	//Getting that card from the deck
	Card* card = cardDeck[index];

	//We put the selected card in the players hand
	this->getHand().push_back(card);

	//We remove the selected card from the deck
	this->deck.erase(this->deck.begin() + index);
	cardDeck.erase(cardDeck.begin() + index);
}

void HumanPlayer::playCard(Player* currentPlayer, Player* enemyPlayer, int index)
{
	//Same simple error checking
	if (index > this->getHand().size() - 1 || index < 0)
	{
		throw "Item out of range";
	}
	else
	{
		//We call the action method of the card played by the player 
		this->getHand()[index]->action(currentPlayer, enemyPlayer);

		//We add this card to the board
		board.addCardToBoard(this->getHand()[index]);

		//We remove this card from the players hand
		this->getHand().erase(this->getHand().begin() + index);
	}
	
	
}


HumanPlayer::~HumanPlayer()
{
}
