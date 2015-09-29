#include "../TestRunner/catch.hpp"
#include "../../SGAEllipse/Source/Population/Individual.h"


TEST_CASE("Individual should")
{
	SECTION("be initialized with a binary vector of 2 x bitsAB + 2 x bitsXY + bitsTheta number of bits")
	{
		Individual individual = Individual(2, 3, 4);
		Individual anotherIndividual = Individual(7, 5, 9);

		CHECK(individual.BinaryVector().size() == 2 * 2 + 3 * 2 + 4);
		CHECK(anotherIndividual.BinaryVector().size() == 7 * 2 + 5 * 2 + 9);
	}

}