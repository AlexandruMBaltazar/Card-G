#pragma once
#include <vector>
#include "Card.h"

class Board
{
private:
	std::vector<Card*> board;
	Card* playedCard;
public:
	Board();

	std::vector<Card*> getBoard() const;
	void setBoard(std::vector<Card*> board);
	Card* getPlayedCard() const;
	void setPlayedCard(Card* played_card);
	void addCardToBoard(Card* card);
	virtual ~Board();
};




