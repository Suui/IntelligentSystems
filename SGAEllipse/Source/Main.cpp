#include <opencv2/core.hpp>
#include <iostream>
#include "Population/Population.h"
#include "Image/Image.h"

using namespace cv;


int main()
{
	Image image = Image("img/ellipses.jpg", 128);	

	Population population = Population(40);

	for (int i = 0; i < 20; i++)
	{
		std::cout << "Generation " << i << " best fitness = " << population.GetIndividual(0).FitnessValue() << std::endl;
		population.OrderByFitnessIn(image);
		population.SetToNextGeneration();
	}

	return 0;
}
