#include "Utility.h"


std::vector<int>& Utility::IntegerToBinaryVector(int value)
{
	std::vector<int> binaryResult;

	while (value / 2 != 0)
	{
		binaryResult.push_back(value % 2);
		value /= 2;
	}

	binaryResult.push_back(value % 2);
	reverse(binaryResult.begin(), binaryResult.end());

	return binaryResult;
}