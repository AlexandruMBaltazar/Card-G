#pragma once
#include "Card.h"
#include "RandomGenerator.h"

/*
 * This class will act as the parent class for the power increase and power decrease card classes
 * PowerCard class inherits from the Card interface
 */
class PowerCard:public Card
{
/*
 * Each power card must have a powerLevel
 * The randomGenerator object is used to generate random power levels
 */
protected:
	int powerLevel;
	RandomGenerator randomGenerator;
public:
	/*
	 *@brief
	 * This constructor can be used to generate a card with a specific power level
	 *
	 * @param power - this is a specific power level we want to use for our power cards
	*/
	PowerCard(int power);
	
	/*
	 *@brief
	 * This constructor can be used to generate a card with a random power level
	 *
	 * @param minPower - This is the minimum power level that our power cards can get
	 * @param maxPower - This is the maximum power level that our power cards can get
	*/
	PowerCard(int minPower, int maxPower);
	virtual ~PowerCard();
};

