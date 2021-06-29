#pragma once
#include "Match.h"
#include "Player.h"

class Match;

class Observer
{
private:
	Match *match;
	Player *humanPlayer;
	Player *virtualPlayer;
public:
	Observer(Match *match, Player *humanPlayer, Player *virtualPlayer);
	virtual void update()= 0;
	virtual ~Observer();
protected:
	Match* getMatch();
	Player* getHumanPlayer();
	Player* getVirtualPlayer();
};

