#include "pch.h"
#include "Board.h"


Board::Board()
{
}

std::vector<Card*> Board::getBoard() const
{
	return board;
}

void Board::setBoard(std::vector<Card*> board)
{
	this->board = board;
}

Card* Board::getPlayedCard() const
{
	return playedCard;
}

void Board::setPlayedCard(Card* played_card)
{
	playedCard = played_card;
}

void Board::addCardToBoard(Card* card)
{
	playedCard = card;
	board.push_back(card);
}


Board::~Board()
{
}