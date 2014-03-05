#pragma once
#include "SolutionMethod.h"
#include "Knapsack_Problem.h"
#include "Knapsack_Solution.h"
#include <stdlib.h>
#include <time.h>

typedef struct {
	Knapsack_Solution sol;
	double prob;									//Probabilidad acumulada de de que la sol sea elegida
}Ind_t;
class AGS_Method :
	public SolutionMethod
{
private:
	Knapsack_Solution bestSolution_;
	Knapsack_Problem problem_;
	vector <Ind_t> pop_;
public:
	AGS_Method();
	~AGS_Method();
	void setBestSolution(Knapsack_Solution);
	void setProblem(Knapsack_Problem);
	Knapsack_Solution getBestSolution();
	Knapsack_Problem getProblem();
	void initialize();								//Inicializa población
	void runSearch();
	void simple_select(vector<Ind_t>&);				//Selecciona padres basandose solo en puntuacion
	void produce(vector<Ind_t>&, vector<Ind_t>&);	//Produce nueva generación
	void cruze_simple(Knapsack_Solution&, Knapsack_Solution&, Knapsack_Solution[]);
	void set_prob();
	void extend(vector<Ind_t>&);					//Extiende población
	void simple_reduction(int);						//Reducción simple a n individuos
	void searchAndSetBest();
};

