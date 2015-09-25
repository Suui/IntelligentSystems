#include <sstream>
#include <ctime>
#include "Individual.h"


Individual::Individual(int minAB, int maxAB, int minXY, int maxXY, int minTheta, int maxTheta)
{
	individual = std::vector<Property>(5);

	SetA(IntegerBetween(minAB, maxAB));
	SetB(IntegerBetween(minAB, maxAB));
	SetXCoord(IntegerBetween(minXY, maxXY));
	SetYCoord(IntegerBetween(minXY, maxXY));
	SetTheta(IntegerBetween(minTheta, maxTheta));

	fitnessValue = 0;

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


std::string Individual::ToDecimalString()
{
	std::ostringstream ostringstream;
	ostringstream	<< "a = " << A().Decimal()
					<< ", b = " << B().Decimal()
					<< ", xCoord = " << XCoord().Decimal()
					<< ", yCoord = " << YCoord().Decimal()
					<< ", theta = " << Theta().Decimal();
	return ostringstream.str();
}


std::string Individual::ToBinaryString()
{
	std::ostringstream ostringstream;
	ostringstream	<< "a = " << A().BinaryString()
					<< ", b = " << B().BinaryString()
					<< ", xCoord = " << XCoord().BinaryString()
					<< ", yCoord = " << YCoord().BinaryString()
					<< ", theta = " << Theta().BinaryString();
	return ostringstream.str();
}
