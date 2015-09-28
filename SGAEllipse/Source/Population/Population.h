#pragma once
#include "Individual.h"
#include "../Image/Image.h"

class FitnessFunction;


class Population
{
	std::vector<Individual> individuals;
	int startingSize;

	FitnessFunction SetFitnessValueFor(Individual& Individual);


public:

	explicit Population(int numberOfIndividuals, int bitsAB = 5, int bitsXY = 6, int bitsTheta = 7);

	Individual& GetIndividual(int index) { return individuals[index]; }

	void OrderByFitnessIn(Image image);
	
	void SetToNextGeneration();
};
