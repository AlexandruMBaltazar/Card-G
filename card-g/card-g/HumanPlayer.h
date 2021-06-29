#pragma once
#include "Player.h"
#include <vector>
// This class represents the human player and it inherits from the Player class
class HumanPlayer :
	public Player
{
public:
	HumanPlayer();
	//The actual implementation of the selectCard for the human player
	void selectCard(std::vector<Card*>& cardDeck, int index) override;
	//The actual implementation of the play method for the human player
	void playCard(Player* currentPlayer, Player* enemyPlayer, int index) override;

	virtual ~HumanPlayer();
};

