#include "Knapsack_Solution.h"


Knapsack_Solution::Knapsack_Solution(int n) : Solution(), n_(n)
{
	item_ = new int[n_];
}


Knapsack_Solution::~Knapsack_Solution()
{
	delete item_;
}

int& Knapsack_Solution::elemento(int i) {

	if (i < 0 || i >= n_)
		throw 10;
	else
		return item_[i];
}