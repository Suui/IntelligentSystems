#include "../TestRunner/catch.hpp"
#include "../../SGAEllipse/Source/Utility.h"


TEST_CASE("Utility should")
{
	SECTION("convert a human-readable ordered binary vector to an integer")
	{
		std::vector<int> binary = { 1, 1, 0 };
		CHECK(Utility::BinaryVectorToDecimal(binary) == 6);
	}

	
}