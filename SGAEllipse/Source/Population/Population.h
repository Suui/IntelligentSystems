#pragma once
#include "Individual.h"
#include "../Image/Image.h"

class FitnessFunction;


class Population
{
	std::vector<Individual> individuals;

	FitnessFunction SetFitnessValueFor(Individual& Individual);


public:

	explicit Population(int numberOfIndividuals, int bitsAB = 5, int bitsXY = 6, int bitsTheta = 7);

	std::vector<Individual> Individuals() const { return individuals; }

	Individual& GetIndividual(int index) { return individuals[index]; }

	int Size() const { return individuals.size(); }

	void OrderByFitnessIn(Image image);
	
	void SetToNextGeneration();
};
