#include "Population/Population.h"
#include "Image/Image.h"
#include <iostream>

const int MAX_ITERATIONS = 10;


int main()
{
	Image image = Image("img/ellipses.jpg", 128);

	Population population = Population(40);

	for (int i = 0; i < MAX_ITERATIONS; i++)
	{
		std::cout << "Generation " << i << " best fitness = " << population.GetIndividual(0).FitnessValue() << std::endl;
		population.OrderByFitnessIn(image);

		for (auto individual : population.Individuals())
			std::cout << individual.ToDecimalString() << std::endl;

		population.DisplayBestEllipseFoundIn(Image("img/ellipses.jpg"));
		population.SetToNextGeneration();
	}

	return 0;
}
