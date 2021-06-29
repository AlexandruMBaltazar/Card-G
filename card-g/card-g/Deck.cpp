#include "pch.h"
#include "Deck.h"
#include <iostream>


void Deck::populateDeck(std::vector<Card*> randomcards)
{
	deck = randomcards;
}

std::vector<Card*>& Deck::getDeck()
{
	return deck;
}

Card* Deck::getCard(int index)
{
	return deck[index];
}

void Deck::displayDeck()
{
	std::cout << "Deck: " << std::endl;

	for (std::vector<Card*>::iterator it = deck.begin(); it != deck.end(); ++it)
	{
		std::cout << std::distance(deck.begin(), it) << ". " << (*it)->getType() << std::endl;

	}
}

Deck::~Deck()
{
}
