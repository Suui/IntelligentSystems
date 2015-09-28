#pragma once
#include <opencv2/core/mat.hpp>


class Image
{
	cv::Mat image;

	bool IsImageLoaded();
	

public:

	explicit Image(std::string imagePath, int threshold);

	void Display();

	int GetPixelAt(int x, int y);

	void SetPixelAt(int x, int y, int value);

	cv::Mat Get() { return image; }
};
