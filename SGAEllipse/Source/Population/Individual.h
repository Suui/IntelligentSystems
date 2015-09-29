#pragma once
#include "Property.h"
#include "../Utility.h"


class Individual
{
	std::vector<Property> properties;
	std::vector<int> binaryVector;
	int fitnessValue;


public:

	Individual();

	Individual(int bitsAB, int bitsXY, int bitsTheta);

	Individual(std::vector<int> fullBinaryVector);

	Property A() { return properties[0]; }

	Property B() { return properties[1]; }

	Property XCoord() { return properties[2]; }

	Property YCoord() { return properties[3]; }

	Property Theta() { return properties[4]; }

	std::vector<int> BinaryVector() { return binaryVector; }

	int FitnessValue() const { return fitnessValue; }

	void SetFitnessValue(int value) { fitnessValue = value; }

	std::string ToDecimalString();

	std::string ToBinaryString();

	std::vector<Property> Properties() { return properties; }
};
