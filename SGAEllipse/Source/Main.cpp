#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include "Population.h"
#include "Image.h"

using namespace cv;


int main()
{
	Image image = Image("../SGAEllipse/img/test.jpg");
	image.Display();

	Population population = Population(20);
	for (auto individual : population.Individuals())
	{
		std::cout << individual.ToDecimalString() << std::endl;	
		std::cout << individual.ToBinaryString() << std::endl;
	}

	return 0;
}
