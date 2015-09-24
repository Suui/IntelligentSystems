#pragma once
#include <vector>

class BinaryIndividual;


class Individual
{
	std::vector<int> individual;
	int bitSizeAB, bitSizeXY, bitSizeTheta;


	void SetA(int value) { individual[0] = value; }
	
	void SetB(int value) { individual[1] = value; }
	
	void SetXCoord(int value) { individual[2] = value; }
	
	void SetYCoord(int value) { individual[3] = value; }
	
	void SetTheta(int value) { individual[4] = value; }

	int IntegerBetween(int min, int max);

	std::vector<int> IntegerToBinaryVector(int value);


public:

	Individual(int minAB, int maxAB, int minXY, int maxXY, int minTheta, int maxTheta);

	int A() { return individual[0]; }

	int B() { return individual[1]; }

	int XCoord() { return individual[2]; }

	int YCoord() { return individual[3]; }

	int Theta() { return individual[4]; }

	std::string ToString();
	
	BinaryIndividual ToBinary();
};
