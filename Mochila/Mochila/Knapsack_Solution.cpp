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

ostream& operator << (ostream& os, Knapsack_Solution sol) {
	int i;
	Bit_set dummy = sol.get_set();

	os << "(";
	for (i = 0; i < dummy.get_size(); i++)
		if (dummy.estado(i))
			os << i;
	for (int j = i; i < dummy.get_size(); j++)
		if (dummy.estado(j))
			os << ", " << j;
		os << ") score: " << sol.get_score();
		return os;
}