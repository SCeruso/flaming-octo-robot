#pragma once
#include "Problem.h"
#include "Solution.h"
#include <iostream>
#include "StopCriterion.h"
class SolutionMethod
{
private:
	//Solution& bestSolution_;
	//Problem& problem_;					//Que sea propiedad de las derivadas
	int iteration_;
	int iterationOfBestSolution_;
	double elapsedTime_;
	double elapsedTimeOfBestSolution_;
	StopCriterion stopCriterion_;
public:
	SolutionMethod();
	~SolutionMethod();
//	Solution& getBestSolution();
//	Problem& getProblem();
	int getIteration();
	int getIterationOfBestSolution();
	double getElapsedTime();
	double getElapsedTimeOfBestSolution();
	StopCriterion& getStopCriterion();
	void setStopCriterion(StopCriterion);
//	void setBestSolution(Solution&);
//	void setProblem(Problem&);
	void resetIteration(); 
	void resetElapsedTime();
	virtual void runSearch() = 0;
	void setIteration(int);
	void increaseIteration();
	void setIterationOfBestSolution(int);
	void setElapsedTimeOfBestSolution(double);
};

