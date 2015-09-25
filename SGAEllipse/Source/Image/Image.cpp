#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include "Image.h"
#include <string>

Image::Image(std::string imagePath, int threshold)
{
	image = imread(imagePath, IMREAD_GRAYSCALE);
	if (!IsImageLoaded()) return;
	
	image = image > threshold;
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


int Image::GetPixelAt(int x, int y)
{
	return image.at<uchar>(x, y);
}


void Image::Display()
{
	namedWindow("Display window", WINDOW_KEEPRATIO); // Create a window for display.
	imshow("Display window", image); // Show our image inside it.
	waitKey(0); // Wait for a keystroke in the window
}
