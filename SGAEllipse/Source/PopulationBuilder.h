#pragma once
#include "Population.h"


class PopulationBuilder
{
	const int NUMBER_OF_PROPERTIES = 29;


public:

	Population Build(int numberOfChromosomes, int imageSize);

	int GetProperty(int imageSize) const;
};
