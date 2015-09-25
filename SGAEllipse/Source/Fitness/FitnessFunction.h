#pragma once
#include "../Population/Individual.h"

class Image;


class FitnessFunction
{
	Individual& individual;


public:

	FitnessFunction(Individual& individual);

	void In(Image image);
};
