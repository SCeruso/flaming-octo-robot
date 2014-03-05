#include "AGS_Method.h"


AGS_Method::AGS_Method() : bestSolution_(), problem_()
{
}


AGS_Method::~AGS_Method()
{
	pop_.clear();
}


void AGS_Method::setBestSolution(Knapsack_Solution sol) {
	bestSolution_ = sol;
}
void AGS_Method::setProblem(Knapsack_Problem prob){
	problem_ = prob;
}
Knapsack_Solution AGS_Method::getBestSolution(){
	return bestSolution_;
}
Knapsack_Problem AGS_Method::getProblem(){
	return problem_;
}
void AGS_Method::initialize() {

	int n = problem_.get_n();
	Bit_set dummy(n);

	pop_.resize(n);
	for (int i = 0; i < n; i++) {
		dummy.insertar(i);
		pop_[i].set_set(dummy);
		dummy.remover(i);
	}
	
}
void AGS_Method::runSearch() {

	setIteration(0);
}