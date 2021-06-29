#include "pch.h"
#include "RandomCardFactory.h"
#include <cstddef>
#include <vector>
#include "PowerCardIncrease.h"
#include "PowerCardDecrease.h"
#include "StealCard.h"
#include "ThiefCatcherCard.h"
#include "EnhancePowerCard.h"
#include <ctime>
using namespace std;


RandomCardFactory::RandomCardFactory()
{
}

/*
 * Each card type is associated with a number
 * A random number is picked, then another number is picked that is different than the previous one and so on...
 * Like this we make sure that the generation is random and there are at least one card per type
 */
std::vector<Card*> RandomCardFactory::createCards(int amount)
{
	int cardValue = 0;
	int enhancePowerCardCounter = 0;
	int thiefCatcherCardCounter = 0;
	
	//Values represents the number associated with our cards
	std::vector<int> values{1, 2, 3, 4, 5};

	//Our generated cards will be stored here
	std::vector<Card*> randomCards;
	
	srand(time(NULL));

	//Make sure that we generate exactly the number of cards specified
	while(randomCards.size() < amount)
	{
		/*
		 *When a card object is generated the value associated with it is removed from the set
		 *this way we make sure that the next random generated value from the set is not the same
		*/
		if (values.empty())
		{
			values = {1,2,3,5};
		}
		else
		{
			int randomIndex = rand() % values.size();

			cardValue = values[randomIndex];

			values.erase(values.begin() + randomIndex);
		}

		//This switch method will create the card object associated with our number
	 	switch (cardValue)
	 	{
	 		case 1:
	 		{
	 			randomCards.push_back(new PowerCardIncrease(1,3));
	 			break;
	 		}
	 	 
	 		case 2:
	 		{
	 			randomCards.push_back(new PowerCardDecrease(1, 3));
	 			break;
	 		}
	 	 
	 		case 3:
	 		{
	 			randomCards.push_back(new StealCard());
	 			break;
	 		}

			case 4:
	 		{
				if (thiefCatcherCardCounter != 1)
				{
					randomCards.push_back(new ThiefCatcherCard());
					++thiefCatcherCardCounter;
				}
				break;
	 		}
			case 5:
	 		{
	 			if (enhancePowerCardCounter != 2)
	 			{
					randomCards.push_back(new EnhancePowerCard ());
					++enhancePowerCardCounter;
	 			}
				break;
	 		}
	 		
	 	}
	
		cardValue = 0;
	}

	return randomCards;

}


RandomCardFactory::~RandomCardFactory()
{
}
