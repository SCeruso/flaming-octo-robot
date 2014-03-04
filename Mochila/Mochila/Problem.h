#pragma once
#include "Solution.h"


class Problem
{
private: 
	bool isMaxProblem_;
public:
	Problem();
	~Problem();
	bool isMaxProblem();
	void setIsMaxProblem(bool);
	bool areEqual(Solution&, Solution&);
	bool firstSolutionIsBetter(Solution&, Solution&);
	virtual double evaluate(Solution&) { return 0; };
};

