#pragma once
#include "Card.h"
#include <vector>

class CardFactory
{
public:
	CardFactory();
	virtual std::vector<Card*> createCards(int amount)=0;
	virtual ~CardFactory();
};

