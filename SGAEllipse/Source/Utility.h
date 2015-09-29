#pragma once
#include <vector>

class Individual;


class Utility
{

public:


	static std::vector<int> RandomBinaryVectorGiven(int bits);

	static int BinaryVectorToDecimal(std::vector<int> binaryVector);

	static int IntegerBetween(int min, int max);

	static void SetRandomSeed();
	
	static std::vector<std::pair<int, int>> GetEllipsePointsFor(Individual individual);
	
	static std::vector<int> IntegerToBinaryVector(int value);

	static std::vector<int> GetSubVector(std::vector<int> Vector, int begin, int end);
};
