#pragma once
#include <opencv2/core/mat.hpp>

using namespace cv;


class Image
{
	Mat image;

	bool IsImageLoaded();
	

public:

	explicit Image(std::string imagePath);

	void Display();
};
