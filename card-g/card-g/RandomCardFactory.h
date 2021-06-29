#pragma once
#include "CardFactory.h"
#include "RandomGenerator.h"
#include <vector>

//This class implements the Factory Method Design Pattern
class RandomCardFactory :
	public CardFactory
{
private:
	RandomGenerator randomGenerator;
public:
	RandomCardFactory();
	/*
	 * @brief
	 * This method is used to generate card objects for our deck
	 * It makes sure that the generation is random and there will always be at least 1 card per type
	 * @param amount - this is the amount of cards we want to generate (e.g. 20)
	 * @return std::vector<Card*> - returns a vector containing pointers to our generated card objects
	 */
	std::vector<Card*> createCards(int amount) override;
	virtual ~RandomCardFactory();
};

