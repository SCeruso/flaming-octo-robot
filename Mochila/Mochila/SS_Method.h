#pragma once
#include "SolutionMethod.h"
#include "Knapsack_Problem.h"
#include "Knapsack_Solution.h"
#include "h_lineal.h"

class SS_Method :
	public SolutionMethod
{
	Knapsack_Solution bestSolution_;
	Knapsack_Problem problem_;
	vector<Knapsack_Solution> pool_;
	vector<Knapsack_Solution> RefSet_;
public:
	SS_Method();
	~SS_Method();
	void setBestSolution(Knapsack_Solution&);
	void setProblem(Knapsack_Problem&);
	Knapsack_Solution getBestSolution();
	Knapsack_Problem getProblem();
	void initialize();
	void runSearch();
	void generatePool();
	void combinar(Knapsack_Solution&, Knapsack_Solution&, Knapsack_Solution&);//PROBADO
	void mejorar();															//FUNCIONA
	void updateRefSet();													//Funciona
	int distancia(Knapsack_Solution&, Knapsack_Solution&);					//PROBADO
	void generar(Knapsack_Solution&, int);									//Genera una solucion
	void shiftSol(Knapsack_Solution&, int);										//Modifica una solucion
	void searchAndSetBest();
};

