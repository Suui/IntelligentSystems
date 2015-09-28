#include "Reproduction.h"


std::vector<int> Reproduction::CrossoverBetween(std::vector<int> firstParent, std::vector<int> secondParent, int crossoverPoint)
{
	std::vector<int> son(firstParent.begin(), firstParent.begin() + crossoverPoint);
	son.insert(son.end(), secondParent.begin() + crossoverPoint, secondParent.end());

	return son;
}


std::vector<Individual> Reproduction::Reproduce(Individual father, Individual mother)
{
	std::vector<Property> fatherProps = father.Properties();
	std::vector<Property> motherProps = mother.Properties();

	std::vector<std::vector<int>> firstSon, secondSon;
	int crossoverPoint;

	for (unsigned int i = 0, size = fatherProps.size(); i < size; i++)
	{
		crossoverPoint = Utility::IntegerBetween(0, fatherProps[i].Binary().size());

		firstSon.push_back(CrossoverBetween(fatherProps[i].Binary(), motherProps[i].Binary(), crossoverPoint));
		secondSon.push_back(CrossoverBetween(motherProps[i].Binary(), fatherProps[i].Binary(), crossoverPoint));
	}

	std::vector<Individual> descendance;
	descendance.push_back(Individual(firstSon[0], firstSon[1], firstSon[2], firstSon[3], firstSon[4]));
	descendance.push_back(Individual(secondSon[0], secondSon[1], secondSon[2], secondSon[3], secondSon[4]));

	return descendance;
}