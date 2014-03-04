#pragma once
#include "Problem.h"
#include <vector>
#include <iostream>
#include "Knapsack_Solution.h"
using namespace std;

typedef struct {
	double v; 						//Valor del elemento
	double w; 						//Peso del elemento
} N_tt;


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
	void read(std::istream& is);	//Función de lectura
};

