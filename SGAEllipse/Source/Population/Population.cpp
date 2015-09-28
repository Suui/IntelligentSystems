#include "Population.h"
#include "../Fitness/FitnessFunction.h"
#include "Reproduction.h"


Population::Population(int numberOfIndividuals, int bitsAB, int bitsXY, int bitsTheta)
{
	for (int i = 0; i < numberOfIndividuals; i++)
		individuals.push_back(Individual(bitsAB, bitsXY, bitsTheta));

	startingSize = numberOfIndividuals;
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

	std::vector<Individual> eliteSons = Reproduction::Reproduce(individuals[0], individuals[1]);
	nextGeneration.insert(nextGeneration.end(), eliteSons.begin(), eliteSons.end());


	std::vector<Individual> sons(2);
	for (int i = 2, size = startingSize / 4 + 1; i < size; i += 1)
	{
		sons = Reproduction::Reproduce(individuals[0], individuals[i]);
		nextGeneration.insert(nextGeneration.end(), sons.begin(), sons.end());

		sons = Reproduction::Reproduce(individuals[1], individuals[i]);
		nextGeneration.insert(nextGeneration.end(), sons.begin(), sons.end());
	}

	individuals = nextGeneration;
}
