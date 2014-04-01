#include "h_lineal.h"


h_lineal::h_lineal(int n, int m) : T_hash(n, m)
{
}


h_lineal::~h_lineal()
{
}
int h_lineal::explorar(int i, int x) {
	int pos;

	srand((2 * x + 1));
	pos = rand() % get_size();

	pos = (pos + i) % get_size();

	return pos;
}