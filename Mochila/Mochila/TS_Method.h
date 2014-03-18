#pragma once
#include "SolutionMethod.h"
#include "Knapsack_Problem.h"
#include "Knapsack_Solution.h"
#include <list>

class TS_Method :
	public SolutionMethod
{
private:
	Knapsack_Solution bestSolution_;
	Knapsack_Problem problem_;
	list<int> tabu_;
	Knapsack_Solution NowSolution_;
	int holgura_;
public:
	TS_Method();
	~TS_Method();
	void setBestSolution(Knapsack_Solution);
	void setProblem(Knapsack_Problem);
	Knapsack_Solution getBestSolution();
	Knapsack_Problem getProblem();
	void setTabu(int);								//Inicializa el tama�o de la lista tab�
	int getTabu();									//Retorna el tama�o de la lista tab�
	void runSearch();
	void initialize();								//Inicializa la soluci�n a un conjunto aleatorio
	void nextSolution();
	bool tabuItem(int);								//Identifica si un elemento est� prohibido
	void set_holgura(int);
};

