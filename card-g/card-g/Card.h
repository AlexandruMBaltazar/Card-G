#pragma once
#include <string>

class Player;

/*
 * The Card class will act as an interface
 * Any future Card classes created will have to inherit from this class
 */
class Card
{
	//Each card will have a name property and a type property
private:
	std::string name;
	std::string type;
public:
	Card();

	/*
	 *@brief
	 *
	 *The action method defines what each card can do (increase power, decrease power, steal)
	 *It is declared virtual as the classes that will inherit it must implement it because different classes
	 *will have different implementations of this method
	 *
	 * @param currentPlayer - This is the player that played the card it can be the virtual or human one
	 * @param enemyPlayer - This is the player that the card was played against
	*/
	virtual void action(Player* currentPlayer, Player* enemyPlayer)=0;

	/*
	 * Getters and Setters
	 */
	std::string getName() const;
	void setName(std::string name);
	std::string getType() const;
	void setType(std::string type);
	virtual ~Card();
};

