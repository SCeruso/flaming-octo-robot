#pragma once
#include "SolutionMethod.h"
#include "Knapsack_Problem.h"
#include "Knapsack_Solution.h"


class AGS_Method :
	public SolutionMethod
{
private:
	Knapsack_Solution bestSolution_;
	Knapsack_Problem problem_;
	vector <Knapsack_Solution> pop_;
public:
	AGS_Method();
	~AGS_Method();
	void setBestSolution(Knapsack_Solution);
	void setProblem(Knapsack_Problem);
	Knapsack_Solution getBestSolution();
	Knapsack_Problem getProblem();
	void runSearch();

};

