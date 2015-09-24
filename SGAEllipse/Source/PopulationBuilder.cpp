#include "PopulationBuilder.h"


Population PopulationBuilder::Build(int numberOfChromosomes, int imageSize)
{
	std::vector<std::vector<int>> chromosomes;

	for (auto i = 0; i < numberOfChromosomes; i++)
	{
		chromosomes.push_back(std::vector<int>());

		for (auto j = 0; j < NUMBER_OF_PROPERTIES; j++)
			chromosomes[i].push_back(GetProperty(imageSize));
	}

	return Population(chromosomes);
}


int PopulationBuilder::GetProperty(int imageSize) const
{
	return rand() % imageSize + 19;
}