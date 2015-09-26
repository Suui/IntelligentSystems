#include "Reproduction.h"


std::vector<Individual> Reproduction::Reproduce(Individual father, Individual mother)
{
	int bitsAB =	father.A().Binary().size();
	int bitsXY =	father.XCoord().Binary().size();
	int bitsTheta = father.Theta().Binary().size();

	return std::vector<Individual>();
}