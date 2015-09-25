#include "FitnessFunction.h"
#include "../Image/Image.h"


FitnessFunction::FitnessFunction(Individual& individual) : individual(individual)
{
}


void FitnessFunction::In(Image image)
{
	individual.SetFitnessValue(6);
}