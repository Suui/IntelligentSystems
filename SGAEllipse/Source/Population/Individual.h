#pragma once
#include "Property.h"
#include "../Utility.h"

class BinaryIndividual;


class Individual
{
	std::vector<Property> individual;
	int fitnessValue;
	int bitSizeAB, bitSizeXY, bitSizeTheta;


	void SetA(std::vector<int> binaryVector) { individual[0] = Property(Utility::BinaryVectorToDecimal(binaryVector), binaryVector); }
	
	void SetB(std::vector<int> binaryVector) { individual[1] = Property(Utility::BinaryVectorToDecimal(binaryVector), binaryVector); }
	
	void SetXCoord(std::vector<int> binaryVector) { individual[2] = Property(Utility::BinaryVectorToDecimal(binaryVector), binaryVector); }
	
	void SetYCoord(std::vector<int> binaryVector) { individual[3] = Property(Utility::BinaryVectorToDecimal(binaryVector), binaryVector); }
	
	void SetTheta(std::vector<int> binaryVector) { individual[4] = Property(Utility::BinaryVectorToDecimal(binaryVector), binaryVector); }


public:

	Individual();

	Individual(int bitsAB, int bitsXY, int bitsTheta);

	Property A() { return individual[0]; }

	Property B() { return individual[1]; }

	Property XCoord() { return individual[2]; }

	Property YCoord() { return individual[3]; }

	Property Theta() { return individual[4]; }

	int FitnessValue() { return fitnessValue; }

	int BitsizeAB() { return bitSizeAB; }
	
	int BitsizeXY() { return bitSizeXY; }

	int BitsizeTheta() { return bitSizeTheta; }

	void SetFitnessValue(int value) { fitnessValue = value; }

	std::string ToDecimalString();

	std::string ToBinaryString();
};
