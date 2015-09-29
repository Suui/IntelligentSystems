#include "Individual.h"
#include "PopulationStatics.h"
#include <sstream>
#include "../Utility.h"


Individual::Individual()
{
	fitnessValue = 0;

	int totalBits = PopulationStatics::bitsAB * 2 + PopulationStatics::bitsXY * 2 + PopulationStatics::bitsTheta;
	binaryVector = Utility::RandomBinaryVectorGiven(totalBits);
}


Individual::Individual(std::vector<int> fullBinaryVector)
{
	fitnessValue = 0;
	binaryVector = fullBinaryVector;	
}


inline Property Individual::A()
{
	std::vector<int> binary = Utility::SubVector(binaryVector, 0, PopulationStatics::bitsAB);
	return Property(Utility::BinaryVectorToDecimal(binary), binary);
}


inline Property Individual::B()
{
	int begin = PopulationStatics::bitsAB;
	std::vector<int> binary = Utility::SubVector(binaryVector, begin, begin + PopulationStatics::bitsAB);
	return Property(Utility::BinaryVectorToDecimal(binary), binary);
}


inline Property Individual::XCoord()
{
	int begin = PopulationStatics::bitsAB * 2;
	std::vector<int> binary = Utility::SubVector(binaryVector, begin, begin + PopulationStatics::bitsXY);
	return Property(Utility::BinaryVectorToDecimal(binary), binary);
}


inline Property Individual::YCoord()
{
	int begin = PopulationStatics::bitsAB * 2 + PopulationStatics::bitsXY;
	std::vector<int> binary = Utility::SubVector(binaryVector, begin, begin + PopulationStatics::bitsXY);
	return Property(Utility::BinaryVectorToDecimal(binary), binary);
}


inline Property Individual::Theta()
{
	int begin = PopulationStatics::bitsAB * 2 + PopulationStatics::bitsXY * 2;
	std::vector<int> binary = Utility::SubVector(binaryVector, begin, begin + PopulationStatics::bitsTheta);
	return Property(Utility::BinaryVectorToDecimal(binary), binary);
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
