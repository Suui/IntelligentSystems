#include "Utility.h"
#include <ctime>


std::vector<int> Utility::RandomBinaryVectorGiven(int bitsAB)
{
	std::vector<int> binaryNumber;

	for (int i = 0; i < bitsAB; i++)
	{
		srand(static_cast<unsigned int>(rand() ^ time(nullptr)));
		binaryNumber.push_back(rand() % 2);
	}

	return binaryNumber;
}


int Utility::BinaryVectorToDecimal(std::vector<int> binaryVector)
{
	int decimal = 0, exponent = 0;

	for (int i = binaryVector.size() - 1; i >= 0; i--)
	{
		decimal += pow(2, exponent) * binaryVector[i];
		exponent += 1;
	}

	return decimal;
}
