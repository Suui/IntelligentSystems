#include "Population/Population.h"
#include "Image/Image.h"
#include <iostream>

const int MAX_ITERATIONS = 40;


int main()
{
	Image image = Image("img/ellipses.jpg", 128);

	Population population = Population(50);

	for (int i = 0; i < MAX_ITERATIONS; i++)
	{
		std::cout << "Generation " << i << " best fitness = " << population.GetIndividual(0).FitnessValue() << std::endl;
		population.OrderByFitnessIn(image);

		population.DisplayBestEllipseFoundIn(Image("img/ellipses.jpg"));
		population.SetToNextGeneration();
	}

	return 0;
}
