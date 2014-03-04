#include "Knapsack_Solution.h"


Knapsack_Solution::Knapsack_Solution() : Solution(), set_(){}


Knapsack_Solution::~Knapsack_Solution() {}

bool Knapsack_Solution::elemento(int i) {
	return set_.estado(i);
}

Bit_set Knapsack_Solution::get_set() {
	return set_;
}
void Knapsack_Solution::set_set(Bit_set set) {
	set_ = set;
}