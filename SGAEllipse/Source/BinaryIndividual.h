#pragma once
#include <vector>


class BinaryIndividual
{
	std::vector<int> binaryIndividual;


public:

	BinaryIndividual(std::vector<int> binaryVector);

	std::string ToString();
};
