#include "FitnessFunction.h"
#include "../Image/Image.h"


FitnessFunction::FitnessFunction(Individual& individual) : individual(individual) {}


void FitnessFunction::In(Image image)
{
	std::vector<std::pair<int, int>> ellipsePoints = Utility::GetEllipsePointsFor(individual);

	int fitnessPoints = 0, x, y;
	for (int i = 0, size = ellipsePoints.size(); i < size; i++)
	{
		x = ellipsePoints[i].first;
		y = ellipsePoints[i].second;
		if (x >= 0 &&  x <= 99 && y >= 0 && y <= 99)
		{
			if (image.GetPixelAt(x, y) == 0)
				fitnessPoints += 1;
		}
	}

	individual.SetFitnessValue(fitnessPoints);
}
