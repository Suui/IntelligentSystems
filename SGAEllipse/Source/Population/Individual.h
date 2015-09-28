#pragma once
#include "Property.h"
#include "../Utility.h"


class Individual
{
	std::vector<Property> properties;
	int fitnessValue;


	void SetA(std::vector<int> binaryVector) { properties[0] = Property(Utility::BinaryVectorToDecimal(binaryVector), binaryVector); }
	
	void SetB(std::vector<int> binaryVector) { properties[1] = Property(Utility::BinaryVectorToDecimal(binaryVector), binaryVector); }
	
	void SetXCoord(std::vector<int> binaryVector) { properties[2] = Property(Utility::BinaryVectorToDecimal(binaryVector), binaryVector); }
	
	void SetYCoord(std::vector<int> binaryVector) { properties[3] = Property(Utility::BinaryVectorToDecimal(binaryVector), binaryVector); }
	
	void SetTheta(std::vector<int> binaryVector) { properties[4] = Property(Utility::BinaryVectorToDecimal(binaryVector), binaryVector); }


public:

	Individual();

	Individual(int bitsAB, int bitsXY, int bitsTheta);

	Individual(std::vector<int> a, std::vector<int> b, std::vector<int> xCoord, std::vector<int> yCoord, std::vector<int> theta);

	Property A() { return properties[0]; }

	Property B() { return properties[1]; }

	Property XCoord() { return properties[2]; }

	Property YCoord() { return properties[3]; }

	Property Theta() { return properties[4]; }

	int FitnessValue() const { return fitnessValue; }

	void SetFitnessValue(int value) { fitnessValue = value; }

	std::string ToDecimalString();

	std::string ToBinaryString();

	std::vector<Property> Properties() { return properties; }
};
