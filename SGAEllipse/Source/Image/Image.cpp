﻿#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include "Image.h"
#include <iostream>
#include <string>


cv::Vec3b const Image::redColor = cv::Vec3b(0, 0, 255);
cv::Vec3b const Image::greenColor = cv::Vec3b(0, 255, 0);
cv::Vec3b const Image::blueColor = cv::Vec3b(155, 0, 0);


Image::Image(std::string imagePath)
{
	image = cv::imread(imagePath, cv::IMREAD_COLOR);
}


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


void Image::SetPixelAt(int x, int y, cv::Vec3b color)
{
	image.at<cv::Vec3b>(cv::Point(x, y)) = color;
}


void Image::Display(int waitKeyTime)
{
	cv::namedWindow("Results image", cv::WINDOW_KEEPRATIO); // Create a window for display.
	cv::imshow("Results image", image); // Show our image inside it.
	cv::waitKey(waitKeyTime);
}
