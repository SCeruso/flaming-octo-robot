#include "Celda.h"


Celda::Celda()
{
}
Celda::~Celda()
{
	cell_.clear();
}
Knapsack_Solution& Celda::block(int i)
{
	return cell_[i];
}

int Celda::get_size(){
	return cell_.size();
}
void Celda::set_size(int n){
	Bit_set dummy;
	Knapsack_Solution sol;
	
	sol.set_set(dummy);

	return cell_.resize(n, sol);
}