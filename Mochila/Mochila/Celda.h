#pragma once
#include "Knapsack_Solution.h"
#include <vector>
using namespace std;

class Celda
{
private:
	vector<Knapsack_Solution> cell_;
public:
	Celda();
	~Celda();
	Knapsack_Solution& block(int);
	int get_size();
	void set_size(int);
};

