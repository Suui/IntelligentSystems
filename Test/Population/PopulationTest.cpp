#include "../TestRunner/catch.hpp"
#include "../../SGAEllipse/Source/Population/Population.h"
#include "../../SGAEllipse/Source/Image/Image.h"


SCENARIO("Population should")
{
	GIVEN("a population with 40 members with default values bitsAB = 5, bitsXY = 6, bitsTheta = 7 and a image")
	{
		Population population = Population(40);
		Image image = Image("../SGAEllipse/img/ellipses.jpg", 128);
		
		THEN("be ordered by fitness values, biggest one first")
		{
			population.OrderByFitnessIn(image);
			int lastFitness = std::numeric_limits<int>::max();
			bool ordered = true;

			for (auto individual : population.Individuals())
			{
				if (individual.FitnessValue() > lastFitness)
				{
					ordered = false;
					break;
				}
				lastFitness = individual.FitnessValue();
			}

			CHECK(ordered);
		}


	}

}
