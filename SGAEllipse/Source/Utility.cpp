#include "Utility.h"
#include <ctime>


std::vector<int> Utility::RandomBinaryVectorGiven(int bits)
{
	std::vector<int> binaryNumber;

	for (int i = 0; i < bits; i++)
	{
		SetRandomSeed();
		binaryNumber.push_back(rand() % 2);
	}

	return binaryNumber;
}


int Utility::BinaryVectorToDecimal(std::vector<int> binaryVector)
{
	int decimal = 0, exponent = 0;

	for (int i = binaryVector.size() - 1; i >= 0; i--)
	{
		decimal += static_cast<int>(pow(2, exponent) * binaryVector[i]);
		exponent += 1;
	}

	return decimal;
}


int Utility::IntegerBetween(int min, int max)
{
	SetRandomSeed();
	return rand() % (max - min + 1) + min;
}


void Utility::SetRandomSeed()
{
	srand(static_cast<unsigned int>(rand() ^ time(nullptr)));
}
