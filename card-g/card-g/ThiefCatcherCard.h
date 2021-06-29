#pragma once
#include "Card.h"
class ThiefCatcherCard :
	public Card
{
public:
	ThiefCatcherCard();

	void action(Player* currentPlayer, Player* enemyPlayer) override;
	virtual ~ThiefCatcherCard();
};

