#include "Mochila.h"

Mochila_t::Mochila_t(void) : n_(0), Cap_(0), V_(NULL), N_(NULL) {}
Mochila_t::Mochila_t(unsigned a, unsigned b) : n_(a), Cap_(b), V_(NULL), N_(NULL) { build_Mochila(); }
Mochila_t :: ~Mochila_t(void) { delete_Mochila(); }

void Mochila_t::delete_Mochila(void)
{
	if (N_ != NULL) {
		delete[]N_;
		N_ = NULL;
	}
	if (V_ != NULL) {
		delete[]V_;
		V_ = NULL;
	}
}

void Mochila_t::build_Mochila(void)
{
	V_ = new it_t[n_*(Cap_ + 1)];
	N_ = new N_t[n_];
	if (N_ == NULL || V_ == NULL)	//Si falla la reserva de memoria
		std::cerr << "ERROR AL RESERVAR MEMORIA" << std::endl;
}

void Mochila_t::read(std::istream& is)
{
	int m, n;
	is >> m >> n;

	Cap_ = m;
	n_ = n;
	build_Mochila();

	for (int i = 0; i<n_; i++) {
		is >> N_[i].v;
		is >> N_[i].w;
	}

}

void Mochila_t::write(std::ostream& os)
{
	char aux[80];

	os << "(Valor, Peso)/Capacidad";
	//os << aux;
	for (int k = 0; k <= Cap_; k++){
		//sprintf(aux, " %4d ", k);
		os << "    " << k;
	}

	os << std::endl;
	for (int i = 0; i<n_; i++){
	//	sprintf(aux, "(%8d, %8d)  |", N_[i].v, N_[i].w);
		os << "(        ," << N_[i].v << "       " << N_[i].w;
		for (int j = 0; j <= Cap_; j++){
			//sprintf(aux, " %4d ", elemento(i, j));
			os << "    " << elemento(i, j);
		}
		os << std::endl;
	}
}

it_t& Mochila_t::elemento(int i, int j)
{
	if ((i<0) || (i>n_) || (j<0) || (j>(Cap_ + 1))){//Si el índice no es válido emite mensaje de error y devuelve por defecto el elemento 0
		std::cerr << "Error accediendo a matriz" << std::endl;
		return V_[0];
	}
	return V_[(i)*(Cap_ + 1) + j];
}

void Mochila_t::create_V(void)
{
	int i, j;

	for (j = 0; j <= Cap_; j++) { //Inicializa la toda la primera fila a su valor con el que finalizará
		if (j<N_[0].w)
			elemento(0, j) = 0;
		else
			elemento(0, j) = N_[0].v;
	}
	for (i = 0; i<n_; i++) {
		elemento(i, 0) = 0; //Toda la primera columna a 0
		for (j = 1; j <= Cap_; j++) {
			if (j < N_[i].w && i != 0)	//Si no es posible colocar otro elemento, toma el valor del elemento anterior
				elemento(i, j) = elemento(i - 1, j);
			else if (i != 0) //Calcula el valor máximo entre colocar o no otro elemento en caso que fuera posible colocar
				elemento(i, j) = fmax(elemento(i - 1, j), N_[i].v + elemento(i - 1, (j - N_[i].w)));
		}
	}
}
