#include "Individual.h"


Individual::Individual(int minAB, int maxAB, int minXY, int maxXY, int minTheta, int maxTheta)
{
	individual = std::vector<int>(5);

	SetA(IntegerBetween(minAB, maxAB));
	SetB(IntegerBetween(minAB, maxAB));
	SetXCoord(IntegerBetween(minXY, maxXY));
	SetYCoord(IntegerBetween(minXY, maxXY));
	SetTheta(IntegerBetween(minTheta, maxTheta));
}