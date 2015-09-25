#include <opencv2/core.hpp>
#include <iostream>
#include "Population/Population.h"
#include "Image/Image.h"

using namespace cv;


int main()
{
	Image image = Image("img/ellipses.jpg", 128);
	image.Display();

	Population population = Population(20);
	for (auto individual : population.Individuals())
	{
		std::cout << individual.ToDecimalString() << std::endl;	
		std::cout << individual.ToBinaryString() << std::endl;
	}

	return 0;
}
