#include "../TestRunner/catch.hpp"
#include "../../SGAEllipse/Source/Utility.h"


TEST_CASE("Utility should")
{
	SECTION("convert a human-readable ordered binary vector to an integer")
	{
		std::vector<int> binary = { 1, 1, 0 };
		CHECK(Utility::BinaryVectorToDecimal(binary) == 6);
	}

	SECTION("convert an integer to a human-readable ordered binary vector")
	{
		std::vector<int> result = { 1, 1, 0 };
		CHECK(Utility::IntegerToBinaryVector(6) == result);
	}

	SECTION("create a human-readable ordered binary vector of the specified length in bits")
	{
		CHECK(Utility::RandomBinaryVectorGiven(5).size() == 5);
		CHECK(Utility::RandomBinaryVectorGiven(38).size() == 38);
	}
}