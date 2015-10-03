#include "Utility.h"
#include "Population/Individual.h"
#include "Image/Image.h"
#include <ctime>


#define _USE_MATH_DEFINES
#include <math.h>


std::vector<int> Utility::RandomBinaryVectorGiven(int bits)
{
	std::vector<int> binaryNumber;

	for (int i = 0; i < bits; i++)
	{
		SetRandomSeed();
		binaryNumber.push_back(rand() % 2);
	}

	return binaryNumber;
}


int Utility::BinaryVectorToDecimal(std::vector<int> binaryVector)
{
	int decimal = 0, exponent = 0;

	for (int i = binaryVector.size() - 1; i >= 0; i--)
	{
		decimal += static_cast<int>(pow(2, exponent) * binaryVector[i]);
		exponent += 1;
	}

	return decimal;
}


int Utility::IntegerBetween(int min, int max)
{
	SetRandomSeed();
	return rand() % (max - min + 1) + min;
}


void Utility::SetRandomSeed()
{
	srand(static_cast<unsigned int>(rand() ^ time(nullptr)));
}


std::vector<std::pair<int, int>> Utility::GetEllipsePointsFor(Individual individual)
{
	int a = individual.A().Decimal() + 5;
	int b = individual.B().Decimal() + 5;
	int x0 = individual.XCoord().Decimal() + 19;
	int y0 = individual.YCoord().Decimal() + 19;
	double theta = individual.Theta().Decimal();
	theta = theta * 89.9 / 127.0 * M_PI / 180;

	int x, y;
	std::vector<std::pair<int, int>> elipsePoints;

	for (double alpha = 0.1; alpha < 180; alpha += 0.1)
	{
		x = static_cast<int>((a*cos(alpha) + x0)*cos(theta) + (b*sin(alpha) + y0)*sin(theta));
		y = static_cast<int>((a*cos(alpha) + x0)*sin(theta) + (b*sin(alpha) + y0)*cos(theta));
		elipsePoints.push_back(std::make_pair(x, y));
	}

	return elipsePoints;
}


std::vector<int> Utility::IntegerToBinaryVector(int value)
{
	std::vector<int> binaryVector = std::vector<int>();

	while (value / 2 != 0)
	{
		binaryVector.push_back(value % 2);
		value /= 2;
	}
	binaryVector.push_back(value);

	reverse(binaryVector.begin(), binaryVector.end());
	return binaryVector;
}


std::vector<int> Utility::SubVector(std::vector<int> vector, int begin, int end)
{
	return std::vector<int>(vector.begin() + begin, vector.begin() + end);
}


void Utility::PlotResults(std::vector<int> results, int numberOfResults)
{
	Image image = Image("img/blankPlot.jpg");
	int maxFitness = 3080;

	for (int i = 0; i < 100; i++)
	{
		image.SetPixelAt(i, 0, Image::greenColor);
		image.SetPixelAt(i, 99, Image::redColor);
	}

	int position = 0;
	for (auto result : results)
	{
		int scaled = 99 - result * 99 / maxFitness;
		image.SetPixelAt(position, scaled, Image::blueColor);
		position += 99 / numberOfResults;
	}

	image.Display(0);
}
