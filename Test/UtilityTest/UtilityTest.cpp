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
}