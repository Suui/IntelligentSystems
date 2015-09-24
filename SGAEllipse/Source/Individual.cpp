#include <sstream>
#include <ctime>
#include "Individual.h"
#include "BinaryIndividual.h"


Individual::Individual(int minAB, int maxAB, int minXY, int maxXY, int minTheta, int maxTheta)
{
	individual = std::vector<int>(5);

	SetA(IntegerBetween(minAB, maxAB));
	SetB(IntegerBetween(minAB, maxAB));
	SetXCoord(IntegerBetween(minXY, maxXY));
	SetYCoord(IntegerBetween(minXY, maxXY));
	SetTheta(IntegerBetween(minTheta, maxTheta));

	bitSizeAB = maxAB - minAB + 1;
	bitSizeXY = maxXY - minXY + 1;
	bitSizeTheta = maxTheta - minTheta + 1;
}


int Individual::IntegerBetween(int min, int max)
{
	srand(static_cast<unsigned int>(rand() ^ time(nullptr)));
	return rand() % (max - min + 1) + min;
}


std::vector<int> Individual::IntegerToBinaryVector(int value)
{
	std::vector<int> binaryResult;

	while (value / 2 != 0)
	{
		binaryResult.push_back(value % 2);
		value /= 2;
	}

	binaryResult.push_back(value % 2);
	reverse(binaryResult.begin(), binaryResult.end());

	return binaryResult;
}


BinaryIndividual Individual::ToBinary()
{
	std::vector<int> binaryVector, binaryResult;

	for (auto value : individual)
	{
		binaryVector = IntegerToBinaryVector(value);
		binaryResult.insert(binaryResult.end(), binaryVector.begin(), binaryVector.end());
	}

	return BinaryIndividual(binaryResult);
}


std::string Individual::ToString()
{
	std::ostringstream ostringstream;
	ostringstream << "a = " << A() << ", b = " << B() << ", xCoord = " << XCoord() << ", yCoord = " << YCoord() << ", theta = " << Theta();
	return ostringstream.str();
}
