#pragma once
#include "Property.h"


class Individual
{
	std::vector<Property> properties;
	std::vector<int> binaryVector;
	int fitnessValue;


public:

	Individual();

	Individual(int bitsAB, int bitsXY, int bitsTheta);

	Individual(std::vector<int> fullBinaryVector);

	inline Property A();

	inline Property B();

	Property XCoord();

	Property YCoord() { return properties[3]; }

	Property Theta() { return properties[4]; }

	std::vector<int> BinaryVector() { return binaryVector; }

	int FitnessValue() const { return fitnessValue; }

	void SetFitnessValue(int value) { fitnessValue = value; }

	std::string ToDecimalString();

	std::string ToBinaryString();

	std::vector<Property> Properties() { return properties; }
};
