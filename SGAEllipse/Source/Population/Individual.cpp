#include "Individual.h"
#include <sstream>
#include "PopulationStatics.h"


Individual::Individual()
{
	fitnessValue = 0;
}


Individual::Individual(int bitsAB, int bitsXY, int bitsTheta)
{
	properties = std::vector<Property>(5);
	fitnessValue = 0;

	int totalBits = bitsAB * 2 + bitsXY * 2 + bitsTheta;
	binaryVector = Utility::RandomBinaryVectorGiven(totalBits);
}


Individual::Individual(std::vector<int> fullBinaryVector)
{
	binaryVector = fullBinaryVector;

	int bitsAB = PopulationStatics::bitsAB;
	int bitsXY = PopulationStatics::bitsXY;
	int bitsTheta = PopulationStatics::bitsTheta;
	
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
