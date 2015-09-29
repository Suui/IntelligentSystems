#include "../TestRunner/catch.hpp"
#include "../../SGAEllipse/Source/Population/Individual.h"
#include "../../SGAEllipse/Source/Population/PopulationStatics.h"


TEST_CASE("Individual should")
{
	GIVEN("a PopulationStatics with 5 bitsAB, 6 bitsXY, 7 bitsTheta")
	{
		PopulationStatics::bitsAB = 5;
		PopulationStatics::bitsXY = 6;
		PopulationStatics::bitsTheta = 7;
		Individual individual = Individual(5, 6, 7);

		THEN("be initialized with a binary vector of 2 x bitsAB + 2 x bitsXY + bitsTheta number of bits")
		{
			int totalBits = PopulationStatics::bitsAB * 2 + PopulationStatics::bitsXY * 2 + PopulationStatics::bitsTheta;
			CHECK(individual.BinaryVector().size() == totalBits);
		}

		THEN("return property A with a binary value of 5 bits")
			CHECK(individual.A().Binary().size() == 5);

		THEN("return property B with a binary value of 5 bits")
			CHECK(individual.B().Binary().size() == 5);

		THEN("return property X with a binary value of 6 bits")
			CHECK(individual.XCoord().Binary().size() == 6);

		THEN("return property Y with a binary value of 6 bits")
			CHECK(individual.YCoord().Binary().size() == 6);

		THEN("return property Theta with a binary value of 7 bits")
			CHECK(individual.Theta().Binary().size() == 7);

	}
}
