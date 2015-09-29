#pragma once
#include "Individual.h"


class Reproduction
{
	static std::vector<int> CrossoverBetween(std::vector<int> firstParent, std::vector<int> secondParent, int firstPoint, int secondPoint);


public:
	
	static std::vector<Individual> Reproduce(Individual father, Individual mother);
};
