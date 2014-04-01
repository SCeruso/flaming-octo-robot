#include "T_hash.h"


T_hash::T_hash(int n, int m)
{
	tabla_.resize(n);
	for (int i = 0; i < n; i++) {
		tabla_[i].set_size(m);
	}
}

T_hash::~T_hash()
{
}

int T_hash::get_size() {
	return tabla_.size();
}

bool T_hash::buscar(int n, int &comp){
	bool parar = false;
	int i = 0;
	int pos;
	bool encontrado = false;


	/*srand((2 * n + 1));
	pos = rand() % get_size();

	for (int j = 0; j < tabla_[pos].get_size(); j++) {
	if (tabla_[pos].block(j) == n){
	encontrado = true;
	parar = true;
	}
	else if (tabla_[pos].block(j) == -1) {
	parar = true;
	}
	}
	*/
	while (!parar){
		pos = explorar(i, n);
		for (int j = 0; j < tabla_[pos].get_size(); j++) {
			comp++;
			if (tabla_[pos].block(j) == n){
				encontrado = true;
				parar = true;
				break;
			}
			else if (tabla_[pos].block(j) == -1) {
				parar = true;
				break;
			}
		}
		i++;
	}

	return encontrado;
}
void T_hash::insertar(int n){
	bool parar = false;
	int i = 0;
	int pos;


	/*srand((2 * n + 1));
	pos = rand() % get_size();

	for (int j = 0; j < tabla_[pos].get_size(); j++) {
	if (tabla_[pos].block(j) == -1) {
	tabla_[pos].block(j) = n;
	parar = true;
	}
	}*/

	while (!parar){
		pos = explorar(i, n);
		//cout << pos << " ";
		for (int j = 0; j < tabla_[pos].get_size(); j++) {
			if (tabla_[pos].block(j) == -1) {
				tabla_[pos].block(j) = n;
				parar = true;
				break;
			}
		}
		i++;
	}
}

void T_hash::write(){

	for (int i = 0; i < tabla_.size(); i++){
		for (int j = 0; j < tabla_[i].get_size(); j++){
			cout << "(" << i << ", " << j << ")" << "\t" << tabla_[i].block(j) << endl;
		}
	}
}

void T_hash::simular_insertar(int n, int &comp){
	bool parar = false;
	int i = 0;
	int pos;

	while (!parar){
		pos = explorar(i, n);
		for (int j = 0; j < tabla_[pos].get_size(); j++) {
			comp++;
			if (tabla_[pos].block(j) == -1) {
				parar = true;
				break;
			}
		}
		i++;
	}
}