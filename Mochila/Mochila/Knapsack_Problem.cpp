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

double Knapsack_Problem::evaluate(Knapsack_Solution& solution) {
	double x = 0;
	double c = 0;

	for (int i = 0; i < n_; i++) {
		if (solution.elemento(i))	{		
			x = x + N_[i].v;
			c = c + N_[i].w;
		}
	}
	if (c > Cap_)
		x = 0;
	solution.set_score(x);
	return x;
}
unsigned Knapsack_Problem::get_n() { return n_; }

unsigned Knapsack_Problem::get_Cap() { return Cap_; }

N_tt Knapsack_Problem::elemento(int i) { return N_[i]; }

void Knapsack_Problem::read(std::istream& is) {
	int m, n;
	is >> m >> n;

	Cap_ = m;
	n_ = n;
	N_.resize(n_);
	for (int i = 0; i<n_; i++) {						
		is >> N_[i].w;
		is >> N_[i].v;
	}
}

