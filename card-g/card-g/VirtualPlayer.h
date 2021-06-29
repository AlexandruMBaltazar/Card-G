#pragma once
#include "Player.h"
#include <vector>

class VirtualPlayer :
	public Player
{

private:
	void playIncreasePowerCard(std::vector<Card*>& powerIncreaseCards, Player* currentPlayer, Player* enemyPlayer);
	void playStealCard(std::vector<Card*>& powerIncreaseCards, Player* currentPlayer, Player* enemyPlayer);
	void playDecreasePowerCard(std::vector<Card*>& powerDecreaseCards, Player* currentPlayer, Player* enemyPlayer);
public:
	VirtualPlayer();
	void selectCard(std::vector<Card*>& cardDeck, int index) override;
	void playCard(Player* currentPlayer, Player* enemyPlayer, int index) override;
	
	virtual ~VirtualPlayer();
};

