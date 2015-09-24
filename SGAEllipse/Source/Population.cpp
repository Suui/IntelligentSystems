#include "Population.h"


Population::Population(const std::vector<std::vector<int>>& chromosomes): chromosomes(chromosomes) {}

std::vector<std::vector<int>> Population::GetChromosomes() const
{
	return chromosomes;
}