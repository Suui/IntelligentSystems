#include "Population/Population.h"
#include "Image/Image.h"
#include <iostream>
#include "Utility.h"

const int MAX_ITERATIONS = 60;


int main()
{
	std::string imagePath = "img/ellipses.jpg";
	Image image = Image(imagePath, 128);

	Population population = Population(100);
	std::vector<int> bestFitnessResults;

	for (int i = 0; i < MAX_ITERATIONS; i++)
	{
		population.OrderByFitnessIn(image);
		bestFitnessResults.push_back(population.GetIndividual(0).FitnessValue());

		std::cout << "Generation " << i << " best fitness = " << bestFitnessResults[i] << std::endl;

		population.DisplayBestEllipseFoundIn(Image(imagePath));
		population.SetToNextGeneration();
	}

	Utility::PlotResults(bestFitnessResults, bestFitnessResults.size());

	return 0;
}
