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

	SetA(Utility::RandomBinaryVectorGiven(bitsAB));
	SetB(Utility::RandomBinaryVectorGiven(bitsAB));
	SetXCoord(Utility::RandomBinaryVectorGiven(bitsXY));
	SetYCoord(Utility::RandomBinaryVectorGiven(bitsXY));
	SetTheta(Utility::RandomBinaryVectorGiven(bitsTheta));

	SetBinaryVectorFromFields();
}


Individual::Individual(std::vector<int> fullBinaryVector)
{
	binaryVector = fullBinaryVector;

	int bitsAB = PopulationStatics::bitsAB;
	int bitsXY = PopulationStatics::bitsXY;
	int bitsTheta = PopulationStatics::bitsTheta;
	
}


void Individual::SetBinaryVectorFromFields()
{
	std::vector<int> a = A().Binary();
	std::vector<int> b = B().Binary();
	std::vector<int> x = XCoord().Binary();
	std::vector<int> y = YCoord().Binary();
	std::vector<int> t = Theta().Binary();

	binaryVector = std::vector<int>();

	binaryVector.insert(binaryVector.end(), a.begin(), a.end());
	binaryVector.insert(binaryVector.end(), b.begin(), b.end());
	binaryVector.insert(binaryVector.end(), x.begin(), x.end());
	binaryVector.insert(binaryVector.end(), y.begin(), y.end());
	binaryVector.insert(binaryVector.end(), t.begin(), t.end());
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
