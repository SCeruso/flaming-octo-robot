#include "Knapsack_Solution.h"


Knapsack_Solution::Knapsack_Solution() : Solution(), set_(), solutionWeight_(0){}


Knapsack_Solution::~Knapsack_Solution() {}

bool Knapsack_Solution::elemento(int i) {
	return set_.estado(i);
}

Bit_set& Knapsack_Solution::get_set() {
	return set_;
}
void Knapsack_Solution::set_set(Bit_set set) {
	set_ = set;
}
double Knapsack_Solution::get_solutionWeight() { return solutionWeight_; }

void Knapsack_Solution::set_solutionWeight(double w) { solutionWeight_ = w; }

ostream& operator << (ostream& os, Knapsack_Solution sol) {
	int i;
	Bit_set dummy = sol.get_set();

	os << "(";
	for (i = 0; i < dummy.get_size(); i++)
		if (dummy.estado(i)) {
			os << i;
			break;
		}
		i++;
		for (; i < dummy.get_size(); i++) {
			if (dummy.estado(i))
				os << ", " << i;
		}
		os << ") score: " << sol.get_score();
		return os;
}

bool Knapsack_Solution::operator == (Knapsack_Solution& sol) {
	
	if (get_score() != sol.get_score())
		return false;
	if (solutionWeight_ != sol.get_solutionWeight())
		return false;
	if (set_ != sol.get_set())
		return false;
	return true;
}
bool Knapsack_Solution::operator != (Knapsack_Solution& sol){
	if (get_score() == sol.get_score())
		return false;
	if (solutionWeight_ == sol.get_solutionWeight())
		return false;
	if (set_ == sol.get_set())
		return false;
	return true;
}