// card-g.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "RandomCardFactory.h"
#include "PowerCardIncrease.h"
#include "PowerCardDecrease.h"
#include "StealCard.h"
#include <ctime>
#include "Deck.h"
#include <string>
#include <algorithm>
#include <thread>
#include "Player.h"
#include "HumanPlayer.h"
#include "VirtualPlayer.h"
#include "Match.h"


// void humanPlayerHUD(Player* humanPlayer)
// {
// 	std::cout << "Your Score: " << humanPlayer->getPower() << std::endl;
// 	std::cout << " " << std::endl;
// 	std::cout << "Your Hand: " << std::endl;
//
// 	for (Card* card : humanPlayer->getHand())
// 	{
// 		std::cout << card->getType() << std::endl;
// 	}
//
// 	std::cout << " " << std::endl;
// 	std::cout << " " << std::endl;
// }
//
// void virtualPlayerHUD(Player* virtualPlayer)
// {
// 	std::cout << "Virtual Player Score: " << virtualPlayer->getPower() << std::endl;
// 	std::cout << " " << std::endl;
// 	std::cout << "Virtual Player Hand: " << std::endl;
//
// 	for (Card* card : virtualPlayer->getHand())
// 	{
// 		std::cout << card->getType() << std::endl;
// 	}
//
// 	std::cout << " " << std::endl;
// 	std::cout << " " << std::endl;
// }
//
// void humanPlayerBoard(Player* humanPlayer)
// {
// 	std::cout << "Your Board: " << std::endl;
// 	for (Card* card : humanPlayer->getBoard())
// 	{
// 		std::cout << card->getType() << std::endl;
// 	}
//
// 	std::cout << " " << std::endl;
// 	std::cout << " " << std::endl;
// }
//
// void virtualPlayerBoard(Player* virtualPlayer)
// {
// 	std::cout << "Virtual Player Board: " << std::endl;
// 	for (Card* card : virtualPlayer->getBoard())
// 	{
// 		std::cout << card->getType() << std::endl;
// 	}
//
// 	std::cout << " " << std::endl;
// 	std::cout << " " << std::endl;
// }
//
// void humanPlayerSelectCard(Player* humanPlayer, Player *virtualPlayer)
// {
// 	int userInput;
//
// 	std::cout << "Please select your card: " << std::endl;
// 	std::cin >> userInput;
// 	humanPlayer->playCard(humanPlayer, virtualPlayer, userInput);
// }
//
// void virtualPlayerSelectCard(Player* virtualPlayer, Player* humanPlayer)
// {
// 	std::cout << "Virtual Player is selecting a card..." << std::endl;
//
// 	std::this_thread::sleep_for(std::chrono::seconds(4));
//
// 	virtualPlayer->playCard(virtualPlayer, humanPlayer);
//
// 	std::cout << " " << std::endl;
//
// }
//
// void humanPlayerSelectCardFromDeck(Player* humanPlayer, Deck* deck)
// {
// 	std::cout << "It is your turn. Please pick a card" << std::endl;
//
// 	int userInput;
//
// 	if (humanPlayer->getHand().size() != 0)
// 	{
// 		std::cout << "Hand: " << std::endl;
//
// 		for (Card* card : humanPlayer->getHand())
// 		{
// 			std::cout << card->getType() << std::endl;
// 		}
// 	}
// 	else
// 	{
// 		std::cout << "Hand: Empty" << std::endl;
// 	}
//
// 	deck->displayDeck();
//
// 	std::cin >> userInput;
//
// 	try
// 	{
// 		humanPlayer->selectCard(deck->getDeck(), userInput);
// 	}catch (const char* msg)
// 	{
// 		system("cls");
// 		std::cout << "Wrong Card ! Please Select Again" << std::endl;
// 		humanPlayerSelectCardFromDeck(humanPlayer, deck);
// 	}
// 	
// 	system("cls");
// }
//
// void virtualPlayerSelectCardFromDeck(Player* virtualPlayer, Deck* deck)
// {
// 	std::cout << "Virtual Player is picking a card" << std::endl;
//
// 	if (virtualPlayer->getHand().size() != 0)
// 	{
// 		std::cout << "Hand: " << std::endl;
//
// 		for (Card* card : virtualPlayer->getHand())
// 		{
// 			std::cout << card->getType() << std::endl;
// 		}
// 	}
// 	else
// 	{
// 		std::cout << "Hand: Empty" << std::endl;
// 	}
//
// 	deck->displayDeck();
//
// 	std::this_thread::sleep_for(std::chrono::seconds(4));
//
// 	virtualPlayer->selectCard(deck->getDeck());
//
// 	system("cls");
// }
//
// void virtualPlayerDisplay(Player* virtualPlayer)
// {
// 	virtualPlayerHUD(virtualPlayer);
// 	virtualPlayerBoard(virtualPlayer);
// }
//
// void humanPlayerDisplay(Player* humanPlayer)
// {
// 	humanPlayerBoard(humanPlayer);
// 	humanPlayerHUD(humanPlayer);
// }

Deck *Deck::instance = NULL;
int main()
{
	Match match;

	match.startMatch();

	// RandomCardFactory randomCardFactory;
	//
	// Deck* deck = Deck::getInstance();
	//
	// deck->populateDeck(randomCardFactory.createCards(20));
	//
	// Player *humanPlayer = new HumanPlayer();
	// Player *virtualPlayer = new VirtualPlayer();
	//
	// int userInput;
	//
	// while (virtualPlayer->getHand().size() < 5 && humanPlayer ->getHand().size() < 5)
	// {
	//
	// 	virtualPlayerSelectCardFromDeck(virtualPlayer, deck);
	//
	// 	humanPlayerSelectCardFromDeck(humanPlayer, deck);
	//
	// }
	//
	// while (true)
	// {
	// 	virtualPlayerDisplay(virtualPlayer);
	// 	if(!virtualPlayer->getHand().empty())
	// 	{
	// 		virtualPlayerSelectCard(virtualPlayer, humanPlayer);
	// 	}
	//
	// 	system("cls");
	//
	// 	virtualPlayerDisplay(virtualPlayer);
	//
	// 	std::cout << " " << std::endl;
	// 	std::cout << " " << std::endl;
	// 	std::cout << " " << std::endl;
	//
	// 	humanPlayerDisplay(humanPlayer);
	// 	if(!humanPlayer->getHand().empty())
	// 	{
	// 		humanPlayerSelectCard(humanPlayer, virtualPlayer);
	// 	}
	// 	
	// 	 system("cls");
	//
	// 	if(humanPlayer->getHand().empty() && virtualPlayer->getHand().empty())
	// 	{
	// 		break;
	// 	}
	// }
	//
	//
	// if (humanPlayer->getPower() > virtualPlayer->getPower())
	// {
	// 	std::cout << "You win with " << humanPlayer->getPower();
	// }
	// else
	// {
	// 	std::cout << "Virtual player won with " << virtualPlayer->getPower();
	// }

}


