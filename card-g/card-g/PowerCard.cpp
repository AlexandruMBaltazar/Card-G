#include "pch.h"
#include "PowerCard.h"

// This constructor can be used to generate a card with a specific power level
PowerCard::PowerCard(int power)
{
	this->powerLevel = power;
}

//This constructor can be used to generate a card with a random power level
PowerCard::PowerCard(int minPower, int maxPower)
{
	//randomGenerator object will generate a random power level between the given power levels 
	this->powerLevel = randomGenerator.generateValue(minPower, maxPower);
}

PowerCard::~PowerCard()
{
}
