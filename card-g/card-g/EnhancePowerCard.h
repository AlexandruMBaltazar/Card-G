#pragma once
#include "Card.h"
class EnhancePowerCard :
	public Card
{
public:
	EnhancePowerCard();

	void action(Player* currentPlayer, Player* enemyPlayer) override;
	virtual ~EnhancePowerCard();
};

