#include "BinaryIndividual.h"
#include <sstream>


BinaryIndividual::BinaryIndividual(std::vector<int> binaryVector)
{
	binaryIndividual = binaryVector;
}


std::string BinaryIndividual::ToString()
{
	std::ostringstream ostringstream;

	for (int number : binaryIndividual)
		ostringstream << number;

	return ostringstream.str();
}
