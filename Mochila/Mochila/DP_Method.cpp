#include "DP_Method.h"


DP_Method::DP_Method() : bestSolution_(), problem_(), Tab_(){}


DP_Method::~DP_Method() {}

void DP_Method::setBestSolution(Knapsack_Solution sol) {
	bestSolution_ = sol;
}
void DP_Method::setProblem(Knapsack_Problem prob){
	problem_ = prob;
}
Knapsack_Solution DP_Method::getBestSolution(){
	return bestSolution_;
}
Knapsack_Problem DP_Method::getProblem(){
	return problem_;
}
void DP_Method::runSearch(){
	Bit_set dummy(problem_.get_n());
	int i, j;
	Tab_.removeMatrix();
	Tab_.buildMatrix(problem_.get_n(), problem_.get_Cap() + 1);

	for (j = 0; j <= problem_.get_Cap(); j++) { //Inicializa la toda la primera fila a su valor con el que finalizará
		if (j<problem_.elemento(0).w)
			Tab_.elemento(1, j + 1).set_score(0);
		else
			Tab_.elemento(1, j + 1).set_score(problem_.elemento(0).v);
	}

	
	for (i = 0; i< problem_.get_n(); i++) {
		Tab_.elemento(i+1, 1).set_score(0); //Toda la primera columna a 0

		for (j = 1; j <= problem_.get_Cap(); j++) {
			if (j <= problem_.elemento(i).w && i != 0)	//Si no es posible colocar otro elemento, toma el valor del elemento anterior
				Tab_.elemento(i + 1, j + 1).set_score(Tab_.elemento(i, j+1).get_score());
			else if (i != 0) //Calcula el valor máximo entre colocar o no otro elemento en caso que fuera posible colocar
				Tab_.elemento(i + 1, j + 1).set_score(fmax(Tab_.elemento(i, j+1).get_score(), problem_.elemento(i).v + Tab_.elemento(i, (j+1 - problem_.elemento(i).w)).get_score()));
		}
	}

	cout << "VALOR MAXIMO" << endl;
	cout << Tab_.elemento(problem_.get_n(), problem_.get_Cap() + 1).get_score() << endl;
}
