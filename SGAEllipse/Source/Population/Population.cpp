#include "Population.h"
#include "../Fitness/FitnessFunction.h"


Population::Population(int numberOfIndividuals, int minAB, int maxAB, int minXY, int maxXY, int minTheta, int maxTheta)
{
	for (int i = 0; i < numberOfIndividuals; i++)
		individuals.push_back(Individual(minAB, maxAB, minXY, maxXY, minTheta, maxTheta));
}


FitnessFunction Population::SetFitnessValueFor(Individual& individual)
{
	return FitnessFunction(individual);
}


void Population::OrderByFitnessIn(Image image)
{
	for (Individual& individual : individuals)
		SetFitnessValueFor(individual).In(image);
	
}
