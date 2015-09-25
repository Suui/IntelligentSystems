#pragma once
#include <vector>


class Property
{
	int decimalValue;
	std::vector<int> binaryValue;

	
public:

	Property();

	Property(int DecimalValue, const std::vector<int>& BinaryValue);
	
	int Decimal() { return decimalValue; }

	std::vector<int> Binary() const { return binaryValue; }

	std::string BinaryString() const;
};
