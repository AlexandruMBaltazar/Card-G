#include "pch.h"
#include "Observer.h"


Observer::Observer(Match* match, Player *humanPlayer, Player *virtualPlayer)
{
	this->humanPlayer = humanPlayer;
	this->virtualPlayer = virtualPlayer;
	this->match = match;
	match->attach(this);
}



Observer::~Observer()
{
}

Match * Observer::getMatch()
{
	return this->match;
}

Player * Observer::getHumanPlayer()
{
	return this->humanPlayer;
}

Player * Observer::getVirtualPlayer()
{
	return this->virtualPlayer;
}
