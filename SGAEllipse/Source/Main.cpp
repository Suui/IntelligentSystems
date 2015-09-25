#include <opencv2/core.hpp>
#include <iostream>
#include "Population/Population.h"
#include "Image/Image.h"

using namespace cv;


int main()
{
	Image image = Image("img/ellipses.jpg", 128);	

	Population population = Population(40);

	population.OrderByFitnessIn(image);
	image.Display();

	for (auto individual : population.Individuals())
	{
		std::cout << individual.ToDecimalString() << std::endl;
		std::cout << individual.ToBinaryString() << std::endl;
		std::cout << individual.FitnessValue() << std::endl;
	}

	return 0;
}
