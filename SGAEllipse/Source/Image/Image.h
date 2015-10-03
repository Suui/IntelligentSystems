#pragma once
#include <opencv2/core/mat.hpp>


class Image
{
	cv::Mat image;

	bool IsImageLoaded();


public:

	static const cv::Vec3b redColor, greenColor, blueColor;


	explicit Image(std::string imagePath);

	explicit Image(std::string imagePath, int threshold);

	void Display(int waitKeyTime);

	int GetPixelAt(int x, int y);

	void SetPixelAt(int x, int y, cv::Vec3b color);

	cv::Mat Get() { return image; }
};
