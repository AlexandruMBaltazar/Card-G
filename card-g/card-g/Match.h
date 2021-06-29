#pragma once
#include "Observer.h"
#include "Deck.h"
#include "Player.h"

class Observer;

//This is the match class where everything is put together to play the match 
class Match
{

private:
	Observer *observer;

private:
	void humanPlayerHUD(Player* humanPlayer);
	void virtualPlayerHUD(Player* virtualPlayer);
	void humanPlayerBoard(Player* humanPlayer);
	void virtualPlayerBoard(Player* virtualPlayer);
	void humanPlayerSelectCard(Player* humanPlayer, Player *virtualPlayer);
	void virtualPlayerSelectCard(Player* virtualPlayer, Player* humanPlayer);
	void humanPlayerSelectCardFromDeck(Player* humanPlayer, Deck* deck);
	void virtualPlayerSelectCardFromDeck(Player* virtualPlayer, Deck* deck);
	void virtualPlayerDisplay(Player* virtualPlayer);
	void humanPlayerDisplay(Player* humanPlayer);

public:
	Match();
	void startMatch();
	void attach(Observer *observer);
	void notify();
	virtual ~Match();
};

