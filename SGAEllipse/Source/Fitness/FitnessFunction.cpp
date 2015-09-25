#include "FitnessFunction.h"
#include "../Image/Image.h"

#define _USE_MATH_DEFINES
#include <math.h>


FitnessFunction::FitnessFunction(Individual& individual) : individual(individual) {}


void FitnessFunction::In(Image image)
{
	int a =			individual.A().Decimal();
	int b =			individual.B().Decimal();
	int x0 =		individual.XCoord().Decimal();
	int y0 =		individual.YCoord().Decimal();
	double theta = individual.Theta().Decimal();
	theta = (theta * 179.0 / 127.0) * M_PI / 180;

	int x, y;
	std::vector<std::pair<int, int>> elipsePoints;

	for (double alpha = 0.2; alpha < 180; alpha += 0.02)
	{
		x = static_cast<int>((a*cos(alpha) + x0)*cos(theta) + (b*sin(alpha) + y0)*sin(theta));
		y = static_cast<int>((a*cos(alpha) + x0)*sin(theta) + (b*sin(alpha) + y0)*cos(theta));
		elipsePoints.push_back(std::make_pair(x, y));
	}

	int fitnessPoints = 0;
	for (int i = 0, size = elipsePoints.size(); i < size; i++)
	{
		x = elipsePoints[i].first;
		y = elipsePoints[i].second;
		if (x >= 0 &&  x <= 99 && y >= 0 && y <= 99)
		{
			if (image.GetPixelAt(x, y) == 0)
				fitnessPoints += 1;
		}
	}

	individual.SetFitnessValue(fitnessPoints);
}