#pragma once


typedef unsigned long  block_t;

class Bit_set
{
	block_t block_;//Conjunto
public:
	Bit_set(void);
	Bit_set(block_t block);
	~Bit_set(void);
	void insertar(int q);
	void remover(int q);
	block_t get_block(void);
	void set_block(block_t Q);
	int pop_ultimo(void);
	int cardinal(void);
	bool estado(int i);//true si "i" contenido en block_
};

