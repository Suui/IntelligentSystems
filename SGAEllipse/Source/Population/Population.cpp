#include "Population.h"
#include "../Fitness/FitnessFunction.h"
#include "Reproduction.h"


Population::Population(int numberOfIndividuals, int bitsAB, int bitsXY, int bitsTheta)
{
	for (int i = 0; i < numberOfIndividuals; i++)
		individuals.push_back(Individual(bitsAB, bitsXY, bitsTheta));
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
	individuals.erase(individuals.begin() + 19, individuals.end());
	
	std::vector<Individual> nextGeneration(individuals.begin(), individuals.begin() + 2);

	std::vector<Individual> eliteSons = Reproduction::Reproduce(individuals[0], individuals[1]);
	nextGeneration.insert(nextGeneration.end(), eliteSons.begin(), eliteSons.end());


	std::vector<Individual> sons(2);
	for (int i = 0; i < Size() - 1; i += 2)
	{

	}

}
