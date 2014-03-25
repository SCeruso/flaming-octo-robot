#include "SS_Method.h"


SS_Method::SS_Method()
{
}


SS_Method::~SS_Method()
{
}
void SS_Method::setBestSolution(Knapsack_Solution& sol) {
	bestSolution_ = sol;
}
void SS_Method::setProblem(Knapsack_Problem& prob){
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
	int poolsz;
	

	if (problem_.get_n() < 10)
		poolsz = problem_.get_n()*problem_.get_n();
	else
		poolsz = 100;

	pool_.resize(poolsz);
	dummy.resize(problem_.get_n());
	sol.set_set(dummy);
	problem_.evaluate(sol);

	while (!parar){
		
		generar(sol, i);

		for (int j = 0; j < i + 1; j++){
			
			shiftSol(sol, i);
			problem_.evaluate(sol);
			pool_[k] = sol;
	
			if (k == (poolsz - 1)){
				parar = true;
				break;
			}
			k++;
			dummy = sol.get_set();
			sol.set_set(dummy.complementario());
			problem_.evaluate(sol);
			pool_[k] = sol;
	
			sol.set_set(dummy);
			problem_.evaluate(sol);
			if (k == (poolsz - 1)){
				parar = true;
				break;
			}
			k++;
		}
		dummy.resize(problem_.get_n());						//Reestablece a 0
		sol.set_set(dummy);
		problem_.evaluate(sol);
		i++;
	}

	mejorar();
	updateRefSet();
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
		if (sol.get_set().estado(j - 1)){								//Verificar
			dummy.insertar(j);
		}
	}
	while (dummy.estado(l) || l == dummy.get_size() ){
		k++;
		l++;
	}
	if (k < n) {
		dummy.insertar(0);
	}
	sol.set_set(dummy);
}

void SS_Method::mejorar() {//Probar
	int j = 0;
	Bit_set dummy;

	for (int i = 0; i < pool_.size(); i++){
		j = problem_.get_n() - 1;
		while (pool_[i].get_solutionWeight() > problem_.get_Cap()){
			dummy = pool_[i].get_set();
			dummy.remover(j);
			pool_[i].set_set(dummy);
			problem_.evaluate(pool_[i]);
			j--;
		}
		j = 0;
		while (problem_.minW(pool_[i]) + pool_[i].get_solutionWeight() <= problem_.get_Cap()){
			if (pool_[i].get_solutionWeight() + problem_.elemento(j).w <= problem_.get_Cap()) {
				dummy = pool_[i].get_set();
				dummy.insertar(j);
				pool_[i].set_set(dummy);
				problem_.evaluate(pool_[i]);
			}
			j++;
		}
	}
}

int SS_Method::distancia(Knapsack_Solution& sol1, Knapsack_Solution& sol2){//Probar
	int dis = 0;
	Bit_set aux1, aux2;

	aux1 = sol1.get_set();
	aux2 = sol2.get_set();

	for (int i = 0; i < problem_.get_n(); i++) {
		if (aux1.estado(i) != aux2.estado(i))
			dis++;
	}

	return dis;
}
void SS_Method::combinar(Knapsack_Solution& sol1, Knapsack_Solution& sol2, Knapsack_Solution& res){	//Probar
	default_random_engine gen;
	double p = sol1.get_score() / (sol1.get_score() + sol2.get_score());
	bernoulli_distribution dis(p);
	Bit_set aux1, aux2;
	Bit_set dummy;

	aux1 = sol1.get_set();
	aux2 = sol2.get_set();
	dummy.resize(problem_.get_n());

	for (int i = 0; i < problem_.get_n(); i++){
		if (aux1.estado(i) == aux2.estado(i)) {
			if (aux1.estado(i))
				dummy.insertar(i);
		}
		else { 
			if (dis(gen)) {
				if (aux1.estado(i))
					dummy.insertar(i);
			}
			else if (aux2.estado(i))
				dummy.insertar(i);
		}
	}
	res.set_set(dummy);
	problem_.evaluate(res);
}

void SS_Method::updateRefSet(){				//PRobar todo esto

	vector<Knapsack_Solution> aux;
	vector<bool> poolused;
	vector<bool> disused;
	vector<bool> refUsed;
	vector<int> dis;
	Knapsack_Solution best;
	Bit_set dummy;
	int rind = -1; 
	int disind = -1;
	int poolind = -1;
	int mindis = 9999;
	int maxdis = -1;

	dis.resize(pool_.size(), 0);
	dummy.resize(problem_.get_Cap());
	best.set_set(dummy);
	problem_.evaluate(best);
	poolused.resize(pool_.size(), false);
	refUsed.resize(RefSet_.size(), false);
	disused.resize(pool_.size(), false);
	aux.resize(10);

	for (int k = 0; k <5; k++){
		for (int i = 0; i < pool_.size(); i++) {
			if ((pool_[i].get_score > best.get_score()) && !poolused[i]) {
				poolind = i;
				rind = -1;
				best = pool_[i];
			}
		}
		for (int i = 0; i < RefSet_.size(); i++) {
			if ((RefSet_[i].get_score > best.get_score()) && !refUsed[i]) {
				rind = i;
				poolind = -1;
				best = RefSet_[i];
			}
		}
		problem_.evaluate(best);
		aux[k] = best;
		
		if (rind != -1) {
			refUsed[rind] = true;
			rind = -1;
		}
		if (poolind != -1) {
			poolused[poolind] = true;
			poolind = -1;
		}
		best.set_set(dummy);
		problem_.evaluate(best);
	}

	for (int k = 0; k < pool_.size(); k++){
		for (int j = 0; j < 5; j++){
			if (distancia(pool_[k], RefSet_[j]) < mindis) {
				mindis = distancia(pool_[k], RefSet_[j]);
			}
		}
		dis[k] = mindis;
		mindis = 99999;
	}
	for (int k = 5; k < 10; k++){
		for (int i = 0; i < dis.size(); i++) {
			if ((dis[i] > maxdis) && !disused[i]) {
				disind = i;
				maxdis = dis[i];
			}
		}
		aux[k] = pool_[disind];
		disused[disind] = true;
	}


	RefSet_ = aux;													//Verificar si se puede

}
void SS_Method::generatePool(){				//Demasiado facil para funcionar :D
	Knapsack_Solution aux;
	vector<Knapsack_Solution> newpool;

	for (int i = 0; i < RefSet_.size(); i++) {
		for (int j = i + 1; j < RefSet_.size(); j++) {
			combinar(RefSet_[i], RefSet_[j], aux);
			newpool.push_back(aux);
		}
	}
	pool_ = newpool;
}
void SS_Method::runSearch(){

}