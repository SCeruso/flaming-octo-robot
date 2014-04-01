#include "Celda.h"


Celda::Celda()
{
}
Celda::~Celda()
{
	cell_.clear();
}
int& Celda::block(int i)
{
	return cell_[i];
}

int Celda::get_size(){
	return cell_.size();
}
void Celda::set_size(int n){
	return cell_.resize(n, -1);
}