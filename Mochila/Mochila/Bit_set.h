#pragma once
#include <iostream>
#include <vector>
#include <random>

using namespace std;

typedef unsigned long  block_t;
typedef unsigned size_t;

class Bit_set
{
	size_t size_;
	vector <block_t> block_;				//Conjunto
public:
	Bit_set(void);
	Bit_set(size_t);
	~Bit_set(void);
	void resize(size_t);
	void insertar(int q);
	void remover(int q);
	block_t get_block(int);
	void set_block(block_t, int);
	//int pop_ultimo(void);
	int cardinal(void);
	bool estado(int i);//true si "i" contenido en block_
	size_t get_size();
	void mutar(double);
	Bit_set complementario();
	friend void cruzar(Bit_set&, Bit_set&, int);
};

