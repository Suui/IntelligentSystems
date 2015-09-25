#include "Population.h"


Population::Population(int numberOfIndividuals, int minAB, int maxAB, int minXY, int maxXY, int minTheta, int maxTheta)
{
	for (int i = 0; i < numberOfIndividuals; i++)
		individuals.push_back(Individual::Individual(minAB, maxAB, minXY, maxXY, minTheta, maxTheta));
}
