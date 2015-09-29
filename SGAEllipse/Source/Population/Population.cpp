#include "Population.h"
#include "PopulationStatics.h"
#include "Reproduction.h"
#include "../Fitness/FitnessFunction.h"
#include "../Utility.h"
#include "../Image/Image.h"
#include <algorithm>


Population::Population(int numberOfIndividuals, int bitsAB, int bitsXY, int bitsTheta)
{
	PopulationStatics::bitsAB = bitsAB;
	PopulationStatics::bitsXY = bitsXY;
	PopulationStatics::bitsTheta = bitsTheta;

	for (int i = 0; i < numberOfIndividuals; i++)
		individuals.push_back(Individual());

	startingSize = numberOfIndividuals;
}


FitnessFunction Population::SetFitnessValueFor(Individual& individual)
{
	return FitnessFunction(individual);
}


void Population::Kill(int individualIndex)
{
	individuals.erase(individuals.begin() + individualIndex);
}


void Population::OrderByFitnessIn(Image image)
{
	for (Individual& individual : individuals)
		SetFitnessValueFor(individual).In(image);
	
	std::sort(individuals.begin(),
			  individuals.end(), 
			  [](Individual first, Individual second) { return first.FitnessValue() > second.FitnessValue(); });
}


void Population::SetToNextGeneration()
{
	// Elitist
	std::vector<Individual> nextGeneration(individuals.begin(), individuals.begin() + 2);

	// Mutation
	nextGeneration.push_back(Individual());
	nextGeneration.push_back(Individual());

	// Two Point Crossover
	std::vector<Individual> sons(2);
	int chosenOnesLeft = startingSize / 2 - 1;

	while (chosenOnesLeft > 1) {
		int chosenFather = Utility::IntegerBetween(0, chosenOnesLeft);
		int chosenMother = Utility::IntegerBetween(0, chosenOnesLeft);

		sons = Reproduction::Reproduce(GetIndividual(chosenFather), GetIndividual(chosenMother));
		nextGeneration.insert(nextGeneration.end(), sons.begin(), sons.end());

		Kill(chosenFather);
		chosenOnesLeft -= 1;

		individuals.shrink_to_fit();
	}

	individuals = nextGeneration;
}


void Population::DisplayBestEllipseFoundIn(Image image)
{
	std::vector<std::pair<int, int>> ellipsePoints = Utility::GetEllipsePointsFor(GetIndividual(0));

	int x, y;
	for (int i = 0, size = ellipsePoints.size(); i < size; i++)
	{
		x = ellipsePoints[i].first;
		y = ellipsePoints[i].second;
		if (x >= 0 && x <= 99 && y >= 0 && y <= 99)
			image.SetPixelAt(x, y, Image::blueColor);
		
	}

	image.Display();
}
