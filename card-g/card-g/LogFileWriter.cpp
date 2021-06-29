#include "pch.h"
#include "LogFileWriter.h"
#include <fstream>
#include <iostream>

int LogFileWriter::turn = 1;

LogFileWriter::LogFileWriter(Match* match, Player *humanPlayer, Player *virtualPlayer): Observer(match, humanPlayer, virtualPlayer)
{
	this->humanPlayer = humanPlayer;
	this->virtualPlayer = virtualPlayer;
}

void LogFileWriter::update()
{
	std::fstream outFile;

	std::string logFileName = "logFile.txt";

	outFile.open(logFileName, std::fstream::app);

	if(outFile.is_open())
	{

		Player *playerInCharge;

		if(turn == 1)
		{
			playerInCharge = getVirtualPlayer();
			--turn;
		}else
		{
			playerInCharge = getHumanPlayer();
			++turn;
		}

		outFile << "Player in charge: " << playerInCharge->getName() << std::endl;
		outFile << "Current Power: " << playerInCharge->getPower() << std::endl;
		outFile << "Card Played: " << playerInCharge->getBoardObj().getPlayedCard()->getType() << std::endl;
		outFile << "Cards In Hand: " << std::endl;

		for (Card* card : playerInCharge->getHand())
		{
			outFile << card->getType() << std::endl;
		}
		outFile << "============== TURN END =============" << std::endl;

		if(humanPlayer->getHand().size() == 0 && virtualPlayer->getHand().size() == 0 )
		{
			if (humanPlayer->getPower() > virtualPlayer->getPower())
			{
				outFile << "Winner is human player" << std::endl;
				outFile << "Final Score: " << humanPlayer->getPower() << std::endl;;
			}
			else if (humanPlayer->getPower() < virtualPlayer->getPower())
			{
				outFile << "Winner is virtual player" << std::endl;
				outFile << "Final Score: " << virtualPlayer->getPower() << std::endl;;
			}
			else
			{
				outFile << "It's a tie" << std::endl;
			}

			outFile << "============== GAME OVER =============" << std::endl;

			outFile.close();
		}
	}
}


LogFileWriter::~LogFileWriter()
{
}
