#include "TS_Method.h"


TS_Method::TS_Method()
{
	holgura_ = 0;
	setTabu(2);
}


TS_Method::~TS_Method()
{
	tabu_.clear();
}
void TS_Method::setBestSolution(Knapsack_Solution sol) {
	bestSolution_ = sol;
}
void TS_Method::setProblem(Knapsack_Problem prob){
	problem_ = prob;
}
Knapsack_Solution TS_Method::getBestSolution(){
	return bestSolution_;
}
Knapsack_Problem TS_Method::getProblem(){
	return problem_;
}
void TS_Method::setTabu(int n){
	tabu_.resize(n, -1);								//Inicializa la lista de elementos tabu a -1
}
int TS_Method::getTabu(){
	return tabu_.size();
}
void TS_Method::initialize(){
	Bit_set dummy(problem_.get_n());
	Knapsack_Solution sol;

	frec_.resize(problem_.get_n(), 1);					//Inicializa el vector de frecuencias

	dummy.mutar(1.0 / problem_.get_n());				//Inicializa la primera soluci�n de forma aleatoria.
	sol.set_set(dummy);
	problem_.evaluate(sol);

	while (sol.get_solutionWeight() > problem_.get_Cap()) {	//Si la soluci�n inicial no es factible, se recupera la factibilidad.
		for (int i = (problem_.get_n() - 1); i >= 0; i--){
			dummy = sol.get_set();
			dummy.remover(i);
			sol.set_set(dummy);
			problem_.evaluate(sol);
		}
	}
	setBestSolution(sol);
	NowSolution_ = sol;
}
void TS_Method::nextSolution(){
	bool quitar = true;
	Bit_set dummy;
	Knapsack_Solution sol;

	dummy = NowSolution_.get_set();

	for (int i = 0; i < problem_.get_n(); i++) {	//Busca si se puede insertar un elemento
		if (!dummy.estado(i) && !tabuItem(i)) {
			dummy.insertar(i);
			sol.set_set(dummy);
			problem_.evaluate(sol);
			if (sol.get_solutionWeight() <= problem_.get_Cap() + holgura_) {	//Se permite sobrepasar el l�mite
				quitar = false;
				tabu_.push_front(i);
				tabu_.pop_back();
	//			frec_[i]++;											//Para que solo cuenten inserciones
				break;
			}
			else {
				dummy.remover(i);
				sol.set_set(dummy);
				problem_.evaluate(sol);
			}
		}
	}

	if (quitar) {										//Si no puede insertar, quita un elemento
		for (int i = problem_.get_n() - 1; i >= 0; i--){
			if (dummy.estado(i) && !tabuItem(i)) {
				dummy.remover(i);
				sol.set_set(dummy);
				problem_.evaluate(sol);
				tabu_.push_front(i);
				tabu_.pop_back();
				break;
			}
		}
	}

	NowSolution_ = sol;
	//////Aumentar frecuencias de todos los elementos presentes////////////////////////
	dummy = sol.get_set();
	for (int i = 0; i< problem_.get_n(); i++){
		if (dummy.estado(i))
			frec_[i]++;
	}
	/////////////////////////////////////////////////////////////////////////
	if (sol.get_score() > getBestSolution().get_score() && sol.get_solutionWeight() <= problem_.get_Cap()){
		setBestSolution(sol);
		setIterationOfBestSolution(getIteration());
		getStopCriterion().iterationReset();
	}
	else
		getStopCriterion().iterationIncrease();
}
bool TS_Method::tabuItem(int n) {
	for (list<int>::iterator it = tabu_.begin(); it != tabu_.end(); it++){
		if (*it == n)
			return true;
	}
	return false;
}
void TS_Method::runSearch(){
	bool parar = false;
	int i = 1;

	initialize();
	//cout << getBestSolution() << endl;
	
	while (!parar){
		increaseIteration();
		nextSolution();
		if (getStopCriterion().getIteration() >= i*10){
			restart();
			//cout << "///////////////Reiniciando soluci�n////////////////////" << endl;
			//cout << NowSolution_ << endl;
			i++;
		}
		parar = getStopCriterion().stop();
		
	}
	cout << "Best: " << getBestSolution() << endl;
	cout << "Iteration:" << getIteration() << endl;
	cout << "Iteration of best solution: " << getIterationOfBestSolution() << endl;
}

void TS_Method::set_holgura(int h) { holgura_ = h; }

void TS_Method::restart() { 

	vector<double> trial;			//Verificar que se usen correctamente los dobles
	double x = 0.0;
	bool llena = false;
	Bit_set dummy;
	Knapsack_Solution sol;
	int sz;
	
	sz = tabu_.size();
	tabu_.clear();
	tabu_.resize(sz, -1);
	dummy.resize(problem_.get_n());
	trial.resize(problem_.get_n(), 0);

	for (int i = 0; i < problem_.get_n(); i++) {
		trial[i] = ((1.0/(double)frec_[i]));
		
	}
	for (int i = 0; i < problem_.get_n(); i++) {
		x = x + trial[i];
	}
	for (int i = 0; i < problem_.get_n(); i++) {
		trial[i] = trial[i] / x;
	}
	for (int i = 1; i < problem_.get_n(); i++) {
		trial[i] = trial[i - 1] + trial[i];
	}
	
	while (!llena){
		x = (double)rand() / (double)RAND_MAX;
		//cout << x << ", ";//**********
		for (int i = 0; i < trial.size(); i++){
			if (x <= trial[i]){
				dummy.insertar(i);
				sol.set_set(dummy);
				problem_.evaluate(sol);
				if (sol.get_solutionWeight() <= problem_.get_Cap() + holgura_) 
					break;
				else {
					dummy.remover(i);
					sol.set_set(dummy);
					problem_.evaluate(sol);
					break;
				}
			}
			
		}
		if (sol.get_solutionWeight() + problem_.minW(sol) > problem_.get_Cap() + holgura_) {//Verificar luego
			llena = true;
		}
	}
	/////////////////////////////////
	//cout << endl;
	/*for (int i = 0; i < problem_.get_n(); i++){
		cout << frec_[i] << ", ";
	}
	cout << endl;*/
	//////////////////////////////////
	/*/////////////////////////////////
	for (int i = 0; i < problem_.get_n(); i++){
		cout << trial[i] << ", ";
	}
	cout << endl;
	//////////////////////////////////*/
	NowSolution_ = sol;
}