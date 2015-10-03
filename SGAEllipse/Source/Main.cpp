#include "Population/Population.h"
#include "Image/Image.h"
#include <iostream>

const int MAX_ITERATIONS = 60;


int main()
{
	std::string imagePath = "img/ellipses.jpg";
	Image image = Image(imagePath, 128);
	image.DisplayConstant();

	Population population = Population(100);

	for (int i = 0; i < MAX_ITERATIONS; i++)
	{
		population.OrderByFitnessIn(image);
		std::cout << "Generation " << i << " best fitness = " << population.GetIndividual(0).FitnessValue() << std::endl;

		population.DisplayBestEllipseFoundIn(Image(imagePath));
		population.SetToNextGeneration();
	}

	return 0;
}
