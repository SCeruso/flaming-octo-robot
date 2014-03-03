#include "Knapsack_Problem.h"


Knapsack_Problem::Knapsack_Problem()
{
	n_ = 0;
	Cap_ = 0;
}


Knapsack_Problem::~Knapsack_Problem()
{
	N_.clear();
}

double Knapsack_Problem::evaluate(Solution& solution) {
	double x = 0;
	double c = 0;
	for (int i = 0; i < n_; i++) {
		if (((Knapsack_Solution&)solution).elemento(i))	{		//????
			x = x + N_[i].v;
			c = c + N_[i].w;
		}
	}
	if (c <= Cap_)
		solution.set_score(x);
	else 
		solution.set_score(0);
}
unsigned Knapsack_Problem::get_n() { return n_; }

unsigned Knapsack_Problem::get_Cap() { return Cap_; }

N_t Knapsack_Problem::elemento(int i) { return N_[i]; }

void Knapsack_Problem::read(std::istream& is) {
	int m, n;
	is >> m >> n;

	Cap_ = m;
	n_ = n;

	for (int i = 0; i<n_; i++) {		//Peso Valor Cantidad
		is >> N_[i].w;
		is >> N_[i].v;
		is >> N_[i].q;
	}
}
