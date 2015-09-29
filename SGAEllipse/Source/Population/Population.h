#pragma once
#include "Individual.h"

class FitnessFunction;
class Image;


class Population
{
	std::vector<Individual> individuals;
	int startingSize;


	FitnessFunction SetFitnessValueFor(Individual& individual);

	void Kill(int individualIndex);


public:

	explicit Population(int numberOfIndividuals, int bitsAB = 5, int bitsXY = 6, int bitsTheta = 7);

	std::vector<Individual> Individuals() { return individuals; }

	Individual& GetIndividual(int index) { return individuals[index]; }

	void OrderByFitnessIn(Image image);

	void SetToNextGeneration();

	void DisplayBestEllipseFoundIn(Image image);
};
