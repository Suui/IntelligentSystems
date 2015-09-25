#pragma once
#include "Individual.h"
#include "../Image/Image.h"


class FitnessFunction;

class Population
{
	std::vector<Individual> individuals;
	int bitSizeAB, bitSizeXY, bitSizeTheta;

	FitnessFunction SetFitnessValueFor(Individual& Individual);


public:

	Population(int numberOfIndividuals, int minAB = 5, int maxAB = 36, int minXY = 19, int maxXY = 82, int minTheta = 0, int maxTheta = 127);

	const std::vector<Individual> Individuals() { return individuals; }

	Individual& GetIndividual(int index) { return individuals[index]; }

	int Size() { return individuals.size(); }

	void OrderByFitnessIn(Image image);
	
	void SetToNextGeneration();
};
