#pragma once
#include "PowerCard.h"
#include <stddef.h>
#include <iostream>

/*
 * This class is used to generate a power increase card object
 * PowerCardIncrease inherits from the PowerCard 
 */
class PowerCardIncrease:public PowerCard
{
public:
	
	/*
	 *@brief
	 * This constructor can be used to generate a power increase card with a specific power level
	 * @param power - this is a specific power level we want to use for our power cards
	*/
	PowerCardIncrease(int power);

	/*
	 *@brief
	 * This constructor can be used to generate a power increase card with a random power level
	 *
	 * @param minPower - This is the minimum power level that our power increase cards can get
	 * @param maxPower - This is the maximum power level that our power increase cards can get
	*/
	PowerCardIncrease(int minPower, int maxPower);

	// This is the actual implementation of the action method inherited from the Card interface
	void action(Player* currentPlayer, Player* enemyPlayer) override;
	virtual ~PowerCardIncrease();
};

