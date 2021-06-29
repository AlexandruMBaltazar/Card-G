#include "pch.h"
#include "Match.h"
#include <ostream>
#include <iostream>
#include "Card.h"
#include "Player.h"
#include <chrono>
#include <thread>
#include "Deck.h"
#include "RandomCardFactory.h"
#include "HumanPlayer.h"
#include "VirtualPlayer.h"
#include "LogFileWriter.h"


Match::Match()
{
}

void Match::startMatch()
{
	RandomCardFactory randomCardFactory;

	Deck* deck = Deck::getInstance();

	deck->populateDeck(randomCardFactory.createCards(20));

	Player *humanPlayer = new HumanPlayer();
	Player *virtualPlayer = new VirtualPlayer();


	LogFileWriter logFileWriter(this, humanPlayer, virtualPlayer);

	while (virtualPlayer->getHand().size() < 5 && humanPlayer->getHand().size() < 5)
	{

		virtualPlayerSelectCardFromDeck(virtualPlayer, deck);

		humanPlayerSelectCardFromDeck(humanPlayer, deck);

	}

	while (true)
	{
		virtualPlayerDisplay(virtualPlayer);
		if (!virtualPlayer->getHand().empty())
		{
			virtualPlayerSelectCard(virtualPlayer, humanPlayer);
		}

		system("cls");

		virtualPlayerDisplay(virtualPlayer);

		notify();

		std::cout << " " << std::endl;
		std::cout << " " << std::endl;
		std::cout << " " << std::endl;

		humanPlayerDisplay(humanPlayer);
		if (!humanPlayer->getHand().empty())
		{
			humanPlayerSelectCard(humanPlayer, virtualPlayer);
		}

		notify();

		system("cls");

		if (humanPlayer->getHand().empty() && virtualPlayer->getHand().empty())
		{
			break;
		}
	}


	if (humanPlayer->getPower() > virtualPlayer->getPower())
	{
		std::cout << "You win with " << humanPlayer->getPower();
	}
	else if(humanPlayer->getPower() < virtualPlayer->getPower())
	{
		std::cout << "Virtual player won with " << virtualPlayer->getPower();
	}
	else
	{
		std::cout << "Tie" << std::endl;;
	}
}

void Match::attach(Observer * observer)
{
	this->observer = observer;
}

void Match::notify()
{
	this->observer->update();
}


Match::~Match()
{
}

void Match::humanPlayerHUD(Player * humanPlayer)
{
	std::cout << "Your Score: " << humanPlayer->getPower() << std::endl;
	std::cout << " " << std::endl;
	std::cout << "Your Hand: " << std::endl;

	for (std::vector<Card*>::iterator it = humanPlayer->getHand().begin(); it != humanPlayer->getHand().end(); ++it)
	{
		std::cout << std::distance(humanPlayer->getHand().begin(), it) << ". " << (*it)->getType() << std::endl;
	}

	std::cout << " " << std::endl;
	std::cout << " " << std::endl;
}

void Match::virtualPlayerHUD(Player* virtualPlayer)
{
	std::cout << "Virtual Player Score: " << virtualPlayer->getPower() << std::endl;
	std::cout << " " << std::endl;
	std::cout << "Virtual Player Hand: " << std::endl;

	for (std::vector<Card*>::iterator it = virtualPlayer->getHand().begin(); it != virtualPlayer->getHand().end(); ++it)
	{
		std::cout << std::distance(virtualPlayer->getHand().begin(), it) << ". " << (*it)->getType() << std::endl;
	}

	
	std::cout << " " << std::endl;
	std::cout << " " << std::endl;
}

void Match::humanPlayerBoard(Player* humanPlayer)
{
	std::cout << "Your Board: " << std::endl;
	for (Card* card : humanPlayer->getBoard())
	{
		std::cout << card->getType() << std::endl;
	}

	std::cout << " " << std::endl;
	std::cout << " " << std::endl;
}

void Match::virtualPlayerBoard(Player* virtualPlayer)
{
	std::cout << "Virtual Player Board: " << std::endl;
	for (Card* card : virtualPlayer->getBoard())
	{
		std::cout << card->getType() << std::endl;
	}

	std::cout << " " << std::endl;
	std::cout << " " << std::endl;
}

void Match::humanPlayerSelectCard(Player* humanPlayer, Player* virtualPlayer)
{
	int userInput;

	std::cout << "Please select your card: " << std::endl;
	std::cin >> userInput;

	try
	{
		humanPlayer->playCard(humanPlayer, virtualPlayer, userInput);
	}
	catch (const char* msg)
	{
		system("cls");
		std::cout << "Wrong Card ! Please Select Again" << std::endl;
		humanPlayer->playCard(humanPlayer, virtualPlayer, userInput);
	}
	
}

void Match::virtualPlayerSelectCard(Player * virtualPlayer, Player * humanPlayer)
{
	std::cout << "Virtual Player is selecting a card..." << std::endl;

	std::this_thread::sleep_for(std::chrono::seconds(4));

	virtualPlayer->playCard(virtualPlayer, humanPlayer);

	std::cout << " " << std::endl;
}

void Match::humanPlayerSelectCardFromDeck(Player* humanPlayer, Deck* deck)
{
	std::cout << "It is your turn. Please pick a card" << std::endl;

	int userInput;

	if (humanPlayer->getHand().size() != 0)
	{
		std::cout << "Hand: " << std::endl;

		for (Card* card : humanPlayer->getHand())
		{
			std::cout << card->getType() << std::endl;
		}
	}
	else
	{
		std::cout << "Hand: Empty" << std::endl;
	}

	deck->displayDeck();

	std::cin >> userInput;

	try
	{
		humanPlayer->selectCard(deck->getDeck(), userInput);
	}
	catch (const char* msg)
	{
		system("cls");
		std::cout << "Wrong Card ! Please Select Again" << std::endl;
		humanPlayerSelectCardFromDeck(humanPlayer, deck);
	}

	system("cls");
}

void Match::virtualPlayerSelectCardFromDeck(Player * virtualPlayer, Deck * deck)
{
	std::cout << "Virtual Player is picking a card" << std::endl;
	if (virtualPlayer->getHand().size() != 0)
	{
		std::cout << "Hand: " << std::endl;

		for (Card* card : virtualPlayer->getHand())
		{
			std::cout << card->getType() << std::endl;
		}
	}
	else
	{
		std::cout << "Hand: Empty" << std::endl;
	}

	deck->displayDeck();

	std::this_thread::sleep_for(std::chrono::seconds(3));

	virtualPlayer->selectCard(deck->getDeck());

	system("cls");
}

void Match::virtualPlayerDisplay(Player * virtualPlayer)
{
	virtualPlayerHUD(virtualPlayer);
	virtualPlayerBoard(virtualPlayer);
}

void Match::humanPlayerDisplay(Player * humanPlayer)
{
	humanPlayerBoard(humanPlayer);
	humanPlayerHUD(humanPlayer);
}
