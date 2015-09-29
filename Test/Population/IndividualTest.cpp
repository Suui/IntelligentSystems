#include "../TestRunner/catch.hpp"
#include "../../SGAEllipse/Source/Population/Individual.h"
#include "../../SGAEllipse/Source/Population/PopulationStatics.h"


TEST_CASE("Individual should")
{
	SECTION("be initialized with a binary vector of 2 x bitsAB + 2 x bitsXY + bitsTheta number of bits")
	{
		Individual individual = Individual(2, 3, 4);
		Individual anotherIndividual = Individual(7, 5, 9);

		CHECK(individual.BinaryVector().size() == 2 * 2 + 3 * 2 + 4);
		CHECK(anotherIndividual.BinaryVector().size() == 7 * 2 + 5 * 2 + 9);
	}

	SECTION("return properties correctly")
	{
		GIVEN("a PopulationStatics with 5 bitsAB, 5 bitsXY, 5 bitsTheta")
		{
			PopulationStatics::bitsAB = 5;
			PopulationStatics::bitsXY = 6;
			PopulationStatics::bitsTheta = 7;
			Individual individual = Individual(5, 6, 7);

			THEN("the Individual should return property A with a binary value of 5 bits")
				CHECK(individual.A().Binary().size() == 5);

			THEN("the Individual should return property B with a binary value of 5 bits")
				CHECK(individual.B().Binary().size() == 5);

			THEN("the Individual should return property X with a binary value of 6 bits")
				CHECK(individual.XCoord().Binary().size() == 6);
		}
	}
}