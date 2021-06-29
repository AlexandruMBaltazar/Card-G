#pragma once
#include "Card.h"
#include <vector>
#include "Board.h"

//HumanPlayer class and VirtualPlayer class will inherit from the Player class interface
class Player
{
	/*
	 * All of the players will have a power level
	 * hand vector representing the cards currently in hand
	 * and a name
	 */
private:
	int power;
	std::vector<Card*> hand;
	std::string name;

	/*
	 * Each player will also have their own board object and the singleton deck to take cards from
	 */
protected:
	Board board;
	std::vector<Card*> deck;
public:
	Player();

	std::string getName();

	void setName(std::string name);

	int getPower() const;

	void setPower(int power);

	std::vector<Card*>& getHand();

	void setHand(std::vector<Card*> cards);

	/*
	 * @brief
	 * Each player class will implement their own method of selecting cards from the deck
	 *
	 * @param cardDeck - the singleton deck
	 * @param index - representing the selected card from the deck
	 */
	virtual void selectCard(std::vector<Card*>& cardDeck, int index = -1) = 0;

	/*
	 * @briefom the deck
	 * Each player class will implement their own method of playing cards 
	 *
	 * @param currentPlayer - the current player
	 * @param enemyPlayer - the player that the current player plays against
	 * @param index - the index of the card played
	 */
	virtual void playCard(Player* currentPlayer, Player* enemyPlayer, int index = -1) = 0;

	std::vector<Card*> getBoard() const;

	void setBoard(Board board);

	Board getBoardObj();

	virtual ~Player();
};

