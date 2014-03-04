#pragma once
#include "SolutionMethod.h"
#include "Knapsack_Problem.h"
#include "Knapsack_Solution.h"
#include "Matrix.h"

class DP_Method :
	public SolutionMethod
{
private:
	Knapsack_Solution bestSolution_;
	Knapsack_Problem problem_;
	Matrix_t <Knapsack_Solution> Tab_;

public:
	DP_Method();
	~DP_Method();
	void setBestSolution(Knapsack_Solution);
	void setProblem(Knapsack_Problem);
	Knapsack_Solution getBestSolution();
	Knapsack_Problem getProblem();
	void runSearch();
};

