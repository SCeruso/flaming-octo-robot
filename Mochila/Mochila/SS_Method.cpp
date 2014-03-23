#include "SS_Method.h"


SS_Method::SS_Method()
{
}


SS_Method::~SS_Method()
{
}
void SS_Method::setBestSolution(Knapsack_Solution sol) {
	bestSolution_ = sol;
}
void SS_Method::setProblem(Knapsack_Problem prob){
	problem_ = prob;
}
Knapsack_Solution SS_Method::getBestSolution(){
	return bestSolution_;
}
Knapsack_Problem SS_Method::getProblem(){
	return problem_;
}

void SS_Method::initialize(){			//PROBAR CONJUNTO INICIAL!!

	Knapsack_Solution sol;
	Bit_set dummy;
	int k = 0;
	bool parar = false;
	int i = 0;

	pool_.resize(problem_.get_n()*problem_.get_n());
	dummy.resize(problem_.get_n());
	sol.set_set(dummy);
	problem_.evaluate(sol);

	while (!parar){
		generar(sol, i);
		for (int j = 0; j < i + 1; j++){
			shiftSol(sol, i);
			problem_.evaluate(sol);
			pool_[i + j] = sol;
			if (i + j == (problem_.get_n()*problem_.get_n() - 1)){
				parar = true;
				break;
			}
			dummy = sol.get_set();
			sol.set_set(dummy.complementario());
			problem_.evaluate(sol);
			pool_[i + j + 1] = sol;
			sol.set_set(dummy);
			problem_.evaluate(sol);
			if (i + j + 1 == (problem_.get_n()*problem_.get_n() - 1)){
				parar = true;
				break;
			}
		}
		i++;
	}
}

void SS_Method::generar(Knapsack_Solution& sol, int i){
	Bit_set dummy;
	int k = 0;

	dummy.resize(sol.get_set().get_size());

	for (int j = 0; j < dummy.get_size(); j++){
		if (k < i) {
			dummy.insertar(j);
			k++;
		}
		else
			k = 0;
	}
	sol.set_set(dummy);
	problem_.evaluate(sol);
}

void SS_Method::shiftSol(Knapsack_Solution& sol, int n){
	Bit_set dummy;
	int l = 1;
	int k = 0;

	dummy.resize(sol.get_set().get_size());

	for (int j = 1; j < dummy.get_size(); j++){
		if (!sol.get_set().estado(j - 1)){
			dummy.insertar(j);
		}
	}
	while (dummy.estado(l)){
		k++;
	}
	if (k < n) {
		dummy.insertar(0);
	}
}