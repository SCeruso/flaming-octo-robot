#pragma once
#include "Solution.h"

class Knapsack_Solution :
	public Solution
{
private:
	int n_;
	int* item_;	//Conjunto solución
public:
	Knapsack_Solution(int);
	~Knapsack_Solution();
	int& elemento(int);
};

