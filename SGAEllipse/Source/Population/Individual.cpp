#include <sstream>
#include "Individual.h"


Individual::Individual()
{
}

Individual::Individual(int bitsAB, int bitsXY, int bitsTheta)
{
	individual = std::vector<Property>(5);

	SetA(Utility::RandomBinaryVectorGiven(bitsAB));
	SetB(Utility::RandomBinaryVectorGiven(bitsAB));
	SetXCoord(Utility::RandomBinaryVectorGiven(bitsXY));
	SetYCoord(Utility::RandomBinaryVectorGiven(bitsXY));
	SetTheta(Utility::RandomBinaryVectorGiven(bitsTheta));
}


std::string Individual::ToDecimalString()
{
	std::ostringstream ostringstream;
	ostringstream	<< "a = " << A().Decimal()
					<< ", b = " << B().Decimal()
					<< ", xCoord = " << XCoord().Decimal()
					<< ", yCoord = " << YCoord().Decimal()
					<< ", theta = " << Theta().Decimal()
					<< ", fitness = " << FitnessValue();
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
