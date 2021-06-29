#include "pch.h"
#include "Card.h"


Card::Card()
{
}

std::string Card::getName() const
{
	return name;
}

void Card::setName(std::string name)
{
	this->name = name;
}

std::string Card::getType() const
{
	return type;
}

void Card::setType(std::string type)
{
	this->type = type;
}


Card::~Card()
{
}
