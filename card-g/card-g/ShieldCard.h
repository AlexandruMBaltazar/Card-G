#pragma once
#include "Card.h"
class ShieldCard :
	public Card
{
public:
	ShieldCard();
	void action(Player* currentPlayer, Player* enemyPlayer) override;
	virtual ~ShieldCard();
};

