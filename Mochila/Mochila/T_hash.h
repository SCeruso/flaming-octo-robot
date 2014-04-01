#pragma once
#include "Celda.h"
#include <iostream>
class T_hash
{
private:
	vector<Celda> tabla_;

public:
	T_hash(int, int);
	~T_hash();
	bool buscar(Knapsack_Solution&);
	void insertar(Knapsack_Solution&);
	int get_size();
	virtual int explorar(int, Knapsack_Solution&) = 0;
	void write();
};

