#pragma once
#include "Individual.h"

class Image;


class FitnessFunction
{
	Individual& individual;


public:

	FitnessFunction(Individual& individual);

	void In(Image image);
};
