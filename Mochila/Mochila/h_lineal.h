#pragma once
#include "T_hash.h"
class h_lineal :
	public T_hash
{
public:
	h_lineal(int, int);
	~h_lineal();
	int explorar(int, Knapsack_Solution&);
};

