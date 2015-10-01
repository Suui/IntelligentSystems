#include "../TestRunner/catch.hpp"
#include "../../SGAEllipse/Source/Population/Individual.h"
#include "../../SGAEllipse/Source/Population/PopulationStatics.h"


SCENARIO("Reproduction should")
{
	GIVEN("two individuals and PopulationStatics with 5 bitsAB, 6 bitsXY, 7 bitsTheta")
	{
		PopulationStatics::bitsAB = 5;
		PopulationStatics::bitsXY = 6;
		PopulationStatics::bitsTheta = 7;

		Individual father = Individual();
		Individual mother = Individual();

		THEN("give two sons by Two Point Crossover at bit level")
		{
			
		}
	}
}