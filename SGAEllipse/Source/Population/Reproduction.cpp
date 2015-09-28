#include "Reproduction.h"
#include "Individual.h"


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

	std::vector<std::vector<int>> sons;
	int crossoverPoint;

	for (unsigned int i = 0, size = fatherProps.size(); i < size; i++)
	{
		crossoverPoint = Utility::IntegerBetween(0, fatherProps[i].Binary().size());

		sons.push_back(CrossoverBetween(fatherProps[i].Binary(), motherProps[i].Binary(), crossoverPoint));
		sons.push_back(CrossoverBetween(motherProps[i].Binary(), fatherProps[i].Binary(), crossoverPoint));
	}

	std::vector<Individual> descendance;
	descendance.push_back(Individual(sons[0], sons[2], sons[4], sons[6], sons[8]));
	descendance.push_back(Individual(sons[1], sons[3], sons[5], sons[7], sons[9]));

	return descendance;
}