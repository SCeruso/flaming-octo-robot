#pragma once
#include "Celda.h"
#include <iostream>
class T_hash
{
private:
	vector<Celda> tabla_;

public:
	T_hash(int, int);
	~T_hash();
	bool buscar(int, int&);
	void insertar(int);
	void simular_insertar(int, int&);
	int get_size();
	virtual int explorar(int, int) = 0;
	void write();
};

