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
		std::vector<int> binary = { 1, 1, 0 };
		CHECK(Utility::IntegerToBinaryVector(6) == binary);
	}

	SECTION("create a human-readable ordered binary vector of the specified length in bits")
	{
		CHECK(Utility::RandomBinaryVectorGiven(5).size() == 5);
		CHECK(Utility::RandomBinaryVectorGiven(38).size() == 38);
	}

	SECTION("return a subvector given a vector and two points to cut")
	{
		std::vector<int> binary =	{ 1, 1, 1, 1, 1, 0, 0, 0, 0, 0 };
		std::vector<int> first =	{ 1, 1, 1, 1, 1 };
		std::vector<int> second =	{ 0, 0, 0, 0, 0 };

		CHECK(Utility::SubVector(binary, 0, 5) == first);
		CHECK(Utility::SubVector(binary, 5, 10) == second);
	}
}