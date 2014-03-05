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
	double max_score = 0;
	Bit_set dummy(n);

	pop_.resize(n);
	for (int i = 0; i < n; i++) {
		dummy.insertar(i);
		pop_[i].sol.set_set(dummy);
		dummy.remover(i);
		
	}
	set_prob();
}
void AGS_Method::set_prob() {
	double max_score = 0;
	int n = problem_.get_n();

	for (int i = 0; i < n; i++)
		max_score = max_score + problem_.evaluate(pop_[i].sol);
	for (int i = 0; i < n; i++)
		pop_[i].prob = pop_[i].sol.get_score() / max_score;

	for (int i = 1; i < n; i++)
		pop_[i].prob = pop_[i].prob + pop_[i - 1].prob;
}
void AGS_Method::runSearch() {

	bool parar = false;
	int n;
	vector <Ind_t> parents;
	vector <Ind_t> des;
	setIteration(0);
	initialize();

	parents.resize(pop_.size());
	des.resize(pop_.size());
	searchAndSetBest();

	while (!parar) {
		simple_select(parents);
		produce(parents, des);
		//MUTAR
		n = pop_.size();
		extend(des);
		simple_reduction(n);
		searchAndSetBest();
		parar = getStopCriterion().stop();
	}

}

void AGS_Method::simple_select(vector<Ind_t>& parent) {
	double x;
	srand((time(NULL)));

	for (int i = 0; i < pop_.size(); i++) {					//Se puede mejorar con busqueda binaria
		x = rand() / RAND_MAX;
		for (int j = 0; j < pop_.size(); j++) {
			if (x <= pop_[j].prob) {
				parent[i] = pop_[j];
			}
		}
	}
}

void AGS_Method::produce(vector<Ind_t>& parent, vector<Ind_t>& des) {

	int i = 0;
	Knapsack_Solution d[2];

	if ((parent.size() % 2) != 0){		//si es impar que quite el último elemento
		parent.pop_back();
		des.pop_back();
	}
	while (i < parent.size()) {
		cruze_simple(parent[i].sol, parent[i + 1].sol, d);
		des[i].sol = d[0];
		des[i + 1].sol = d[1];
		i += 2;
	}
}

void AGS_Method::cruze_simple(Knapsack_Solution& p1, Knapsack_Solution& p2, Knapsack_Solution d[]) {
	int point;
	int l = p1.get_set().get_size();
	Bit_set des1;
	Bit_set des2;

	srand((time(NULL)));

	point = rand() % (l - 1);

	des1 = p1.get_set();
	des2 = p2.get_set();

	cruzar(des1, des2, point);

	d[0].set_set(des1);
	problem_.evaluate(d[0]);
	d[1].set_set(des2);
	problem_.evaluate(d[1]);
}

void AGS_Method::extend(vector<Ind_t>& des) {

	for (int i = 0; i < des.size(); i++)
		pop_.push_back(des[i]);
}

void AGS_Method::simple_reduction(int n) {
	vector <Ind_t> dummy;
	dummy.resize(pop_.size() - n);

	for (int i = n; i < pop_.size(); i++) {
		dummy[i - n] = pop_[i];
	}
	pop_.clear();
	pop_ = dummy;
}

void AGS_Method::searchAndSetBest(){
	Knapsack_Solution aux;

	for (int i = 0; i <= pop_.size(); i++) {
		if (aux.get_score() < pop_[i].sol.get_score())
			aux = pop_[i].sol;
	}
	if (aux.get_score() > getBestSolution().get_score()){
		setBestSolution(aux);
		getStopCriterion().iterationReset();
	}
	else{
		getStopCriterion().iterationIncrease();
	}


}