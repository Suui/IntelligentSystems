#pragma once
#include "Property.h"

class BinaryIndividual;


class Individual
{
	std::vector<Property> individual;
	int fitnessValue;
	int bitSizeAB, bitSizeXY, bitSizeTheta;


	void SetA(int value) { individual[0] = Property(value, IntegerToBinaryVector(value)); }
	
	void SetB(int value) { individual[1] = Property(value, IntegerToBinaryVector(value)); }
	
	void SetXCoord(int value) { individual[2] = Property(value, IntegerToBinaryVector(value)); }
	
	void SetYCoord(int value) { individual[3] = Property(value, IntegerToBinaryVector(value)); }
	
	void SetTheta(int value) { individual[4] = Property(value, IntegerToBinaryVector(value)); }

	int IntegerBetween(int min, int max);

	std::vector<int> IntegerToBinaryVector(int value);


public:

	Individual(int minAB, int maxAB, int minXY, int maxXY, int minTheta, int maxTheta);

	Property A() { return individual[0]; }

	Property B() { return individual[1]; }

	Property XCoord() { return individual[2]; }

	Property YCoord() { return individual[3]; }

	Property Theta() { return individual[4]; }

	int FitnessValue() { return fitnessValue; }

	void SetFitnessValue(int value) { fitnessValue = value; }

	std::string ToDecimalString();

	std::string ToBinaryString();
};
