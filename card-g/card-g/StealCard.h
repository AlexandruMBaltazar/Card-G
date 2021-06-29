#pragma once
#include "Card.h"
#include <iostream>

class StealCard :
	public Card
{
public:
	StealCard();
	void action(Player* currentPlayer, Player* enemyPlayer) override;
	~StealCard();
};

