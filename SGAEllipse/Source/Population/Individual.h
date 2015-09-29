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

	std::vector<int> BinaryVector() { return binaryVector; }

	inline Property A();

	inline Property B();

	inline Property XCoord();

	inline Property YCoord();

	inline Property Theta();

	int FitnessValue() const { return fitnessValue; }

	void SetFitnessValue(int value) { fitnessValue = value; }

	std::string ToDecimalString();

	std::string ToBinaryString();

	std::vector<Property> Properties() { return properties; }
};
