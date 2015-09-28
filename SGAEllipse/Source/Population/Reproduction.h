#pragma once
#include <vector>

class Individual;


class Reproduction
{
	static std::vector<int> CrossoverBetween(std::vector<int> dadPiece, std::vector<int> momPiece, int crossoverPoint);

public:

	static std::vector<Individual> Reproduce(Individual father, Individual mother);
};
