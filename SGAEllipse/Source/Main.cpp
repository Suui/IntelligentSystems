#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include "Population.h"
#include "PopulationBuilder.h"

using namespace cv;


void DisplayImage(std::string imagePath)
{
	Mat image;
	image = imread(imagePath, IMREAD_COLOR); // Read the file

	if (image.empty()) // Check for invalid input
	{
		std::cout << "Could not open or find the image" << std::endl;
		return;
	}

	namedWindow("Display window", WINDOW_KEEPRATIO); // Create a window for display.
	imshow("Display window", image); // Show our image inside it.
	waitKey(0); // Wait for a keystroke in the window
}


int main()
{
	DisplayImage("../SGAEllipse/img/image.jpg");

	Population population = PopulationBuilder().Build(10, 100);
	std::cout << population.GetChromosomes().size() << std::endl;

	return 0;
}
