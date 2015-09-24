#include "Individual.h"


Individual::Individual()
{
	individual = std::vector<int>(5);
		
	SetA(IntegerBetween(5, 36));
	SetB(IntegerBetween(5, 36));
	SetXCoord(IntegerBetween(19, 82));
	SetYCoord(IntegerBetween(19, 82));
	SetTheta(IntegerBetween(0, 127));
}
