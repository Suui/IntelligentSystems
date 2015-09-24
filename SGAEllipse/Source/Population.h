#pragma once
#include <vector>
#include "Individual.h"


class Population
{
	std::vector<Individual> individuals;


public:

	Population(int numberOfIndividuals, int minAB = 5, int maxAB = 36, int minXY = 19, int maxXY = 82, int minTheta = 0, int maxTheta = 127);

	Individual Individual(int index) { return individuals[index]; }
};
