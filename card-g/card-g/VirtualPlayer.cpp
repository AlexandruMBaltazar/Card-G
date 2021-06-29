#include "pch.h"
#include "VirtualPlayer.h"
#include "StealCard.h"
#include <vector>
#include <algorithm>
#include "PowerCardIncrease.h"


VirtualPlayer::VirtualPlayer() : Player()
{
	setName("Virtual Player");
}

void VirtualPlayer::selectCard(std::vector<Card*>& cardDeck, int index = -1)
{
	int randomIndex = rand() % cardDeck.size();

	this->deck = cardDeck;

	Card* card = cardDeck[randomIndex];

	this->getHand().push_back(card);

	this->deck.erase(this->deck.begin() + randomIndex);
	cardDeck.erase(cardDeck.begin() + randomIndex);
}

void VirtualPlayer::playCard(Player* currentPlayer, Player* enemyPlayer, int index)
{
	std::vector<Card*> powerIncreaseCards;
	std::vector<Card*> powerDecreaseCards;
	std::vector<Card*> stealCards;

	for (int i = 0; i < this->getHand().size(); i++)
	{

		if (this->getHand()[i]->getName() == "Steal Card")
		{
			stealCards.push_back(this->getHand()[i]);
		}
		else if (this->getHand()[i]->getName() == "Power Card Increase")
		{
			powerIncreaseCards.push_back(this->getHand()[i]);
		}
		else
		{
			powerDecreaseCards.push_back(this->getHand()[i]);
		}
	}
	
	int itr;
	// Card* playedCard;

	std::sort(powerIncreaseCards.begin(), powerIncreaseCards.end(), [](const Card* lhs, const Card* rhs) {
		return lhs->getType() > rhs->getType();
	});

	std::sort(powerDecreaseCards.begin(), powerDecreaseCards.end(), [](const Card* lhs, const Card* rhs) {
		return lhs->getType() > rhs->getType();
	});

	if (this->board.getBoard().empty())
	{
		if (!stealCards.empty())
		{
			playStealCard(stealCards, currentPlayer, enemyPlayer);
		}
		else if (!powerIncreaseCards.empty())
		{
			playIncreasePowerCard(powerIncreaseCards, currentPlayer, enemyPlayer);
		}
		else
		{
			playDecreasePowerCard(powerDecreaseCards, currentPlayer, enemyPlayer);
		}
	}
	else if (enemyPlayer->getHand().empty())
	{
		if (!powerIncreaseCards.empty())
		{
			playIncreasePowerCard(powerIncreaseCards, currentPlayer, enemyPlayer);
		}
		else if (!powerDecreaseCards.empty())
		{
			playDecreasePowerCard(powerDecreaseCards, currentPlayer, enemyPlayer);
		}
		else
		{
			playStealCard(stealCards, currentPlayer, enemyPlayer);
		}
	}
	else if(enemyPlayer->getBoardObj().getPlayedCard()->getName() == "Power Card Increase")
	{
		if (!powerDecreaseCards.empty())
		{
			playDecreasePowerCard(powerDecreaseCards, currentPlayer, enemyPlayer);
		}
		else if (!powerIncreaseCards.empty())
		{
			playIncreasePowerCard(powerIncreaseCards, currentPlayer, enemyPlayer);
		}
		else
		{
			playStealCard(stealCards, currentPlayer, enemyPlayer);
		}
	}
	else if (enemyPlayer->getBoardObj().getPlayedCard()->getName() == "Power Card Decrease")
	{
		if(!powerIncreaseCards.empty())
		{
			playIncreasePowerCard(powerIncreaseCards, currentPlayer, enemyPlayer);
		}
		else if (!powerDecreaseCards.empty())
		{
			playDecreasePowerCard(powerDecreaseCards, currentPlayer, enemyPlayer);
		}
		else
		{
			playStealCard(stealCards, currentPlayer, enemyPlayer);
		}
	}
	else if(enemyPlayer->getBoardObj().getPlayedCard()->getName() == "Steal Card" || 
		enemyPlayer->getBoardObj().getPlayedCard()->getName() == "Thief Catcher Card" 
		|| enemyPlayer->getBoardObj().getPlayedCard()->getName() == "EnhancePowerCard")
	{
		if(enemyPlayer->getHand().back()->getName() == "Power Card Increase")
		{
			if (!powerDecreaseCards.empty())
			{
				playDecreasePowerCard(powerDecreaseCards, currentPlayer, enemyPlayer);
			}
			else if (!powerIncreaseCards.empty())
			{
				playIncreasePowerCard(powerIncreaseCards, currentPlayer, enemyPlayer);
			}
			else
			{
				playStealCard(stealCards, currentPlayer, enemyPlayer);
			}
		}
		else if(enemyPlayer->getHand().back()->getName() == "Power Card Decrease")
		{
			if (!powerIncreaseCards.empty())
			{
				playIncreasePowerCard(powerIncreaseCards, currentPlayer, enemyPlayer);
			}
			else if (!powerDecreaseCards.empty())
			{
				playDecreasePowerCard(powerDecreaseCards, currentPlayer, enemyPlayer);
			}
			else
			{
				playStealCard(stealCards, currentPlayer, enemyPlayer);
			}
		}
		else
		{
			if (!stealCards.empty())
			{
				playStealCard(stealCards, currentPlayer, enemyPlayer);
			}
			else if (!powerIncreaseCards.empty())
			{
				playIncreasePowerCard(powerIncreaseCards, currentPlayer, enemyPlayer);
			}
			else
			{
				playDecreasePowerCard(powerDecreaseCards, currentPlayer, enemyPlayer);
			}
		}
		
	}

}

void VirtualPlayer::playIncreasePowerCard(std::vector<Card*>& powerIncreaseCards, Player* currentPlayer, Player* enemyPlayer)
{
	Card* playedCard;
	playedCard = powerIncreaseCards[0];
	playedCard->action(currentPlayer, enemyPlayer);
	board.addCardToBoard(playedCard);
	this->getHand().erase(std::remove(this->getHand().begin(), this->getHand().end(), playedCard), this->getHand().end());
	enemyPlayer->getBoardObj().setPlayedCard(nullptr);
}

void VirtualPlayer::playStealCard(std::vector<Card*>& stealCards, Player* currentPlayer, Player* enemyPlayer)
{
	Card* playedCard;
	playedCard = stealCards[0];
	playedCard->action(currentPlayer, enemyPlayer);
	board.addCardToBoard(playedCard);
	this->getHand().erase(std::remove(this->getHand().begin(), this->getHand().end(), playedCard), this->getHand().end());
	stealCards.erase(stealCards.begin());
	enemyPlayer->getBoardObj().setPlayedCard(nullptr);
}

void VirtualPlayer::playDecreasePowerCard(std::vector<Card*>& powerDecreaseCards, Player* currentPlayer, Player* enemyPlayer)
{
	Card* playedCard;
	playedCard = powerDecreaseCards[0];
	playedCard->action(currentPlayer, enemyPlayer);
	board.addCardToBoard(playedCard);
	this->getHand().erase(std::remove(this->getHand().begin(), this->getHand().end(), playedCard), this->getHand().end());
	powerDecreaseCards.erase(powerDecreaseCards.begin());
	enemyPlayer->getBoardObj().setPlayedCard(nullptr);
}

VirtualPlayer::~VirtualPlayer()
{
}

