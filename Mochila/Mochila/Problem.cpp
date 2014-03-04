#include "Problem.h"


Problem:: Problem() : isMaxProblem_(true) {}

Problem:: ~Problem(){}

bool Problem:: isMaxProblem() { return isMaxProblem_; }

void Problem:: setIsMaxProblem(bool isMax) { isMaxProblem_ = isMax; }

bool Problem::areEqual(Solution& solution1, Solution& solution2){
	if (solution1.get_score() != NON_EVALUATED)
		evaluate(solution1);
	if (solution2.get_score() != NON_EVALUATED)
		evaluate(solution2);
	return solution1.get_score() == solution2.get_score() ? true : false; 
}

bool Problem::firstSolutionIsBetter(Solution& solution1, Solution& solution2){
	if (solution1.get_score() != NON_EVALUATED)
		evaluate(solution1);
	if (solution2.get_score() != NON_EVALUATED)
		evaluate(solution2);
	return solution1.get_score() > solution2.get_score() ? true : false;
}
