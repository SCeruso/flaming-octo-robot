#pragma once
#include "Solution.h"
#include "Bit_set.h"

class Knapsack_Solution :
	public Solution
{
private:
	Bit_set set_;	//Conjunto solución
public:
	Knapsack_Solution();
	~Knapsack_Solution();
	bool elemento(int);
	Bit_set get_set();
	void set_set(Bit_set);
};

