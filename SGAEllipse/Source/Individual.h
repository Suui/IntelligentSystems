#pragma once
#include <vector>

class Individual
{
	std::vector<int> individual;


	int SetA(int value) { individual[0] = value; }

	int SetB(int value) { individual[1] = value; }

	int SetXCoord(int value) { individual[2] = value; }

	int SetYCoord(int value) { individual[3] = value; }

	int SetTheta(int value) { individual[4] = value; }

	int IntegerBetween(int min, int max) { return rand() % (max - min + 1) + min; }


public:

	Individual();

	int A() { return individual[0]; }

	int B() { return individual[1]; }

	int XCoord() { return individual[2]; }

	int YCoord() { return individual[3]; }

	int Theta() { return individual[4]; }
};
