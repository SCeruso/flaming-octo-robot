#pragma once
#include "Problem.h"
#include <vector>
#include <iostream>
#include "Knapsack_Solution.h"
#include <algorithm>
using namespace std;

class N_tt{
public:
	double v; 						//Valor del elemento
	double w; 						//Peso del elemento
	bool operator<(const N_tt &j) { return ((this->v / this->w) > (j.v / j.w)); }		//CUIDADO! Para ordenar de mayor a menor sin necesidad de usar reverse.
} ;



class Knapsack_Problem :
	public Problem
{
private:
	unsigned n_;					//Número de elementos
	unsigned Cap_;					//Capacidad
	vector <N_tt> N_;				//Vector de elementos
public:
	Knapsack_Problem();
	~Knapsack_Problem();
	double evaluate(Knapsack_Solution&);
	unsigned get_n();
	unsigned get_Cap();
	N_tt elemento(int);				//Devuelve el un elemento del vector
	void ordenar();					//Ordena según rendimiento de cada objeto
	void read(std::istream& is);	//Función de lectura
	
};

