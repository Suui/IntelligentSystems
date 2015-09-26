#include <sstream>
#include "Individual.h"


Individual::Individual()
{
}

Individual::Individual(int bitsAB, int bitsXY, int bitsTheta)
{
	properties = std::vector<Property>(5);

	SetA(Utility::RandomBinaryVectorGiven(bitsAB));
	SetB(Utility::RandomBinaryVectorGiven(bitsAB));
	SetXCoord(Utility::RandomBinaryVectorGiven(bitsXY));
	SetYCoord(Utility::RandomBinaryVectorGiven(bitsXY));
	SetTheta(Utility::RandomBinaryVectorGiven(bitsTheta));
}


Individual::Individual(std::vector<int> a, std::vector<int> b, std::vector<int> xCoord, std::vector<int> yCoord, std::vector<int> theta)
{
	properties = std::vector<Property>(5);

	SetA(a);
	SetB(b);
	SetXCoord(xCoord);
	SetYCoord(yCoord);
	SetTheta(theta);
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
