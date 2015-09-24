#pragma once
#include <vector>


class Population
{
	const std::vector<std::vector<int>> chromosomes;


public:

	explicit Population(const std::vector<std::vector<int>>& chromosomes);

	std::vector<std::vector<int>> GetChromosomes() const;
};
