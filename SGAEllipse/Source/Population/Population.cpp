#include "Population.h"
#include "../Fitness/FitnessFunction.h"


Population::Population(int numberOfIndividuals, int minAB, int maxAB, int minXY, int maxXY, int minTheta, int maxTheta)
{
	for (int i = 0; i < numberOfIndividuals; i++)
		individuals.push_back(Individual(minAB, maxAB, minXY, maxXY, minTheta, maxTheta));

	bitSizeAB = maxAB - minAB + 1;
	bitSizeXY = maxXY - minXY + 1;
	bitSizeTheta = maxTheta - minTheta + 1;
}


FitnessFunction Population::SetFitnessValueFor(Individual& individual)
{
	return FitnessFunction(individual);
}


void Population::OrderByFitnessIn(Image image)
{
	for (Individual& individual : individuals)
		SetFitnessValueFor(individual).In(image);
	
	std::sort(individuals.begin(),
			  individuals.end(), 
			  [](Individual first, Individual second) { return first.FitnessValue() > second.FitnessValue(); });
}


void Population::SetToNextGeneration()
{
	std::vector<Individual> nextGeneration(individuals.begin(), individuals.begin() + 2);
	
	individuals.erase(individuals.begin() + 18, individuals.end());

	for (int i = 0; i < Size() - 1; i += 2)
	{
		
	}

}
