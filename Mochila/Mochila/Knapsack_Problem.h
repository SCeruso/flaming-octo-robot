#pragma once
#include "Problem.h"
#include <vector>
#include <iostream>
#include "Knapsack_Solution.h"
using namespace std;

typedef struct {
	double v; 						//Valor del elemento
	double w; 						//Peso del elemento
	unsigned q;						//Cantidad disponible del elemento
}N_t;


class Knapsack_Problem :
	public Problem
{
private:
	unsigned n_;					//Número de elementos
	unsigned Cap_;					//Capacidad
	std::vector <N_t> N_;			//Vector de elementos
public:
	Knapsack_Problem();
	~Knapsack_Problem();
	double evaluate(Solution&);
	unsigned get_n();
	unsigned get_Cap();
	N_t elemento(int);				//Devuelve el un elemento del vector
	void read(std::istream& is);	//Función de lectura
};

