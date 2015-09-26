#pragma once
#include <vector>


class Utility
{

public:

	static std::vector<int> RandomBinaryVectorGiven(int bits);

	static int BinaryVectorToDecimal(std::vector<int> binaryVector);
};
