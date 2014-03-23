#include "Bit_set.h"


Bit_set::Bit_set(void): size_(0) {}

Bit_set::Bit_set(size_t size)  {

	int x;

	if (size <= 0)
		throw 2;
	else {
		size_ = size;
		x = size / (sizeof(block_t)* 8);
		block_.resize(x + 1);
		for (int i = 0; i < block_.size(); i++)
			block_[i] = 0;
	}

}

Bit_set :: ~Bit_set(void) { block_.clear(); }

void Bit_set::resize(size_t size) {
	block_.clear();

	int x;

	if (size <= 0)
		throw 2;
	else {
		size_ = size;
		x = size / (sizeof(block_t)* 8);
		block_.resize(x + 1);
		for (int i = 0; i < block_.size(); i++)
			block_[i] = 0;
	}

}

void Bit_set::insertar(int q) {
	block_t aux = 1;
	int x;
	int pos;
	if (q > size_)
		throw 3;
	else {
		x = q / (sizeof(block_t)* 8);
		pos = q % (sizeof(block_t)* 8);

		aux = aux << (pos);
		block_[x] = block_[x] | aux;
	}
}

void Bit_set::remover(int q) {
	block_t aux = 1;
	int x;
	int pos;
	if (q > size_)
		throw 3;
	else {
		x = q / (sizeof(block_t)* 8);
		pos = q % (sizeof(block_t)* 8);

		aux = aux << (pos);
		aux = ~aux;

		block_[x] = block_[x] & aux;
	}
}

block_t Bit_set::get_block(int x) { return block_[x]; }

void Bit_set::set_block(block_t Q, int x) { block_[x] = Q; }
/*
int Bit_set::pop_ultimo(void) {

	int i = 0;
	block_t aux = 1;
	block_t dummy = block_;
	if (block_ != 0) {
		while ((dummy & aux) != 1){
			i++;
			dummy = dummy >> (1);
		}
	}
	else
		i = -1;

	remover(i);
	return i;


}*/

int Bit_set::cardinal(void)  {

	int i = 0;
	block_t aux;
	block_t dummy = 1;

	for (int j = 0; j < block_.size(); j++){
		aux = block_[j];
		while (aux != 0) {
			if ((aux & dummy) != 0)
				i++;
			aux = aux >> (1);

		}
	}
	return i;

}

bool Bit_set::estado(int i) {
	
	block_t aux = 1;
	bool e;
	int x, pos;

	x = i / (sizeof(block_t)* 8);
	pos = i % (sizeof(block_t)* 8);

	aux = aux << (pos);
	aux = aux & block_[x];

	if (aux != 0)
		e = true;
	else
		e = false;
	return e;


}
size_t Bit_set::get_size() {
	return size_;
}

void cruzar(Bit_set& p1, Bit_set& p2, int point) {
	int i = 0;
	Bit_set dummy1;
	Bit_set dummy2;

	dummy1.resize(p1.get_size());
	dummy2.resize(p1.get_size());

	for (i = 0; i <= point; i++) {
		if (p1.estado(i))
			dummy1.insertar(i);
		if (p2.estado(i))
			dummy2.insertar(i);
	}

	for (; i < p1.get_size(); i++) {
		if (p1.estado(i))
			dummy2.insertar(i);
		if (p2.estado(i))
			dummy1.insertar(i);
	}
	p1 = dummy1;
	p2 = dummy2;
}

void Bit_set::mutar(double p) {

	default_random_engine gen;
	bernoulli_distribution dis(p);

	for (int i = 0; i < size_; i++){
		if (dis(gen)) {
			if (estado(i))
				remover(i);
			else
				insertar(i);
		}
	}

}
Bit_set Bit_set::complementario(){
	Bit_set dummy;

	dummy.resize(size_);
	
	for (int i = 0; i < size_; i++) {
		if (!estado(i))
			dummy.insertar(i);
	}
	return dummy;
}