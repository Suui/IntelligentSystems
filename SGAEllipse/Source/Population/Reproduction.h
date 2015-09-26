#pragma once
#include "Individual.h"


class Reproduction
{
	static std::vector<int> CrossoverBetween(std::vector<int> dadPiece, std::vector<int> momPiece, int crossoverPoint);

public:

	static std::vector<Individual> Reproduce(Individual father, Individual mother);
};
