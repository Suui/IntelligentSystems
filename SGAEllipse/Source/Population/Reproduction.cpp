#include "Reproduction.h"
#include "../Utility.h"


std::vector<int> Reproduction::CrossoverBetween(std::vector<int> firstParent, std::vector<int> secondParent, int firstPoint, int secondPoint)
{
	std::vector<int> son(firstParent.begin(), firstParent.begin() + firstPoint);
	
	son.insert(son.end(), secondParent.begin() + firstPoint, secondParent.begin() + secondPoint);
	son.insert(son.end(), firstParent.begin() + secondPoint, firstParent.end());

	return son;
}


std::vector<Individual> Reproduction::Reproduce(Individual father, Individual mother)
{
	std::vector<int> fatherBinary = father.BinaryVector();
	std::vector<int> motherBinary = mother.BinaryVector();

	int firstCrossOverPoint, secondCrossOverPoint;

	firstCrossOverPoint = Utility::IntegerBetween(0, fatherBinary.size());
	secondCrossOverPoint = Utility::IntegerBetween(0, fatherBinary.size());

	std::vector<int> firstSon = CrossoverBetween(fatherBinary, motherBinary, firstCrossOverPoint, secondCrossOverPoint);
	std::vector<int> secondSon = (CrossoverBetween(motherBinary, motherBinary, firstCrossOverPoint, secondCrossOverPoint));

	std::vector<Individual> descendance;
	descendance.push_back(Individual(firstSon));
	descendance.push_back(Individual(secondSon));

	return descendance;
}