#pragma once

/*
 * This class is used to generate random values for power levels
 */
class RandomGenerator
{
public:
	RandomGenerator();

	/*
	 * @brief
	 * This method is used to generate a random number between two given values
	 * 
	 * @param min - This is the minimum value
	 * @param max - This is the maximum value
	 *
	 * @return int - the generated number (power)
	 */
	int generateValue(int min, int max);
	virtual ~RandomGenerator();
};

