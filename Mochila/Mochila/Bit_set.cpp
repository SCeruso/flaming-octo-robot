#include "Bit_set.h"


Bit_set::Bit_set(void) : block_(0) {}

Bit_set::Bit_set(block_t block) : block_(block) {}

Bit_set :: ~Bit_set(void) {}

void Bit_set::insertar(int q) {
	block_t aux = 1;

	aux = aux << (q);
	block_ = block_ | aux;
}

void Bit_set::remover(int q) {
	block_t aux = 1;

	aux = aux << (q);
	aux = ~aux;

	block_ = block_ & aux;
}

block_t Bit_set::get_block(void) { return block_; }

void Bit_set::set_block(block_t Q) { block_ = Q; }

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


}

int Bit_set::cardinal(void)  {

	int i = 0;
	block_t aux;
	aux = block_;
	block_t dummy = 1;

	while (aux != 0) {
		if ((aux & dummy) != 0)
			i++;
		aux = aux >> (1);

	}

	return i;

}

bool Bit_set::estado(int i) {
	block_t aux = 1;
	bool e;

	aux = aux << (i);
	aux = aux & block_;

	if (aux != 0)
		e = true;
	else
		e = false;
	return e;


}
