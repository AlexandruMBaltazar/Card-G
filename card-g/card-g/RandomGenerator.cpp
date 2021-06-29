#include "pch.h"
#include "RandomGenerator.h"
#include <cstdint>
#include <random>
#include <ctime>


RandomGenerator::RandomGenerator()
{
}

int RandomGenerator::generateValue(int min, int max)
{
	int randNum = (rand() % 3) + 1;

	return randNum;
}


RandomGenerator::~RandomGenerator()
{
}
