#pragma once
#include "PowerCard.h"
#include <iostream>

/*
 * This class represents a power decrease card
 * It inherits from the PowerCard class
 * It does the same thing as the PowerCardIncrease class except it implements the action method differently
 */

class PowerCardDecrease :
	public PowerCard
{
public:
	PowerCardDecrease(int minPower, int maxPower);
	void action(Player* currentPlayer, Player* enemyPlayer) override;
	virtual ~PowerCardDecrease();
	bool operator <(const PowerCardDecrease & powerCard) const
	{
		return powerLevel < powerCard.powerLevel;
	}
};

