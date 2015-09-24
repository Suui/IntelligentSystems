#include "Individual.h"
#include <sstream>


Individual::Individual(int minAB, int maxAB, int minXY, int maxXY, int minTheta, int maxTheta)
{
	individual = std::vector<int>(5);

	SetA(IntegerBetween(minAB, maxAB));
	SetB(IntegerBetween(minAB, maxAB));
	SetXCoord(IntegerBetween(minXY, maxXY));
	SetYCoord(IntegerBetween(minXY, maxXY));
	SetTheta(IntegerBetween(minTheta, maxTheta));
}

std::string Individual::ToString()
{
	std::ostringstream ostringstream;
	ostringstream << "a = " << A() << ", b = " << B() << ", xCoord = " << XCoord() << ", yCoord = " << YCoord() << ", theta = " << Theta();
	return ostringstream.str();
}