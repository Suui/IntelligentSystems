﻿#include "Image.h"
#include <opencv2/imgcodecs.hpp>
#include <iostream>
#include <opencv2/highgui.hpp>


Image::Image(std::string imagePath)
{
	image = imread(imagePath, IMREAD_GRAYSCALE);
	if (!IsImageLoaded()) return;
	

}


bool Image::IsImageLoaded()
{
	if (image.empty())
	{
		std::cerr << "Image was not loaded properly, is the image path correct?" << std::endl;
		return false;
	}

	return true;
}


void Image::Display()
{
	namedWindow("Display window", WINDOW_KEEPRATIO); // Create a window for display.
	imshow("Display window", image); // Show our image inside it.
	waitKey(0); // Wait for a keystroke in the window
}
