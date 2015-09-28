#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include "Image.h"
#include <iostream>
#include <string>


Image::Image(std::string imagePath, int threshold)
{
	image = cv::imread(imagePath, cv::IMREAD_GRAYSCALE);
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


void Image::SetPixelAt(int x, int y, int value)
{
	image.at<uchar>(x, y) = value;
}


void Image::Display()
{
	cv::namedWindow("Display window", cv::WINDOW_KEEPRATIO); // Create a window for display.
	cv::imshow("Display window", image); // Show our image inside it.
	cv::waitKey(0); // Wait for a keystroke in the window
}
