#pragma once
#include "Observer.h"
class LogFileWriter :
	public Observer
{
private :
	static int turn;
	 Player* humanPlayer = nullptr;
	 Player* virtualPlayer = nullptr;
public:
	LogFileWriter(Match* match, Player *humanPlayer, Player *virtualPlayer);
	void update() override;
	virtual ~LogFileWriter();
};

