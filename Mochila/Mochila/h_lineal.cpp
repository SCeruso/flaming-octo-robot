#include "h_lineal.h"


h_lineal::h_lineal(int n, int m) : T_hash(n, m)
{
}


h_lineal::~h_lineal()
{
}
int h_lineal::explorar(int i, Knapsack_Solution& x) {
	int pos;

	srand((7 * x.get_score() + 3*x.get_solutionWeight() + 1));
	pos = rand() % get_size();

	pos = (pos + i) % get_size();

	return pos;
}