#pragma once

#include <iostream>
#include <math.h>
#include<stdio.h>

using namespace std;

typedef unsigned int 	sz_t;											// Tipo del tamaño
typedef unsigned int 	ix_t;											// Tipo del índice


template <class it_t> class Matrix_t{
private:
	it_t*    	base_;													// Vector que contiene los elementos de la matriz
	sz_t 		m_;														// Número de filas
	sz_t 		n_;														// Número de columna

public:

	void buildMatrix(void);	
	void buildMatrix(sz_t, sz_t);										// Reserva Memoria
	void removeMatrix(void);											// Libera Memoria

	Matrix_t(sz_t m, sz_t n);											// Constructor
	Matrix_t(void);														// Constructor por defecto
	Matrix_t(const Matrix_t&);											//Constructor de copia
	virtual ~Matrix_t(void);											// Destructor

	it_t& elemento(ix_t i, ix_t j);										// Acceso al elemento (i,j)
	it_t& elemento(ix_t i, ix_t j) const;
	sz_t  nfilas(void) const;											// Devuelve el número de filas
	sz_t  ncolumnas(void) const;										// Devuelve el número de columna

	void write(std::ostream& os);										// Mostrar la matriz
	void read(std::istream& is);										// Mostrar la matriz

	Matrix_t<it_t>& operator= (const Matrix_t <it_t> &);
	Matrix_t<it_t> operator+ (const Matrix_t <it_t> &)const;			//*this+M
	Matrix_t<it_t> operator- (const Matrix_t <it_t> &) const;

	bool operator!= (const Matrix_t <it_t> &) const;
	bool operator== (const Matrix_t <it_t> &) const;
	//---------------------------------------------------------------------------//
	// ESTOS Métodos son para el cálculo del determinante !!!!                   //
	//---------------------------------------------------------------------------//
private:
	int  signo(ix_t i, ix_t j);						// Devuelve (-1)^(i+j)

	void subMatriz(ix_t i, ix_t j, Matrix_t& SM);	// Construye una submatrix
													// eliminando la fila i y la columna j
													// de la matriz llamante
public:
	it_t determinante(int &c);

};

template <class it_t> Matrix_t<it_t>::Matrix_t(void) : base_(NULL), m_(0), n_(0) {}
template <class it_t> Matrix_t <it_t>::Matrix_t(sz_t m, sz_t n) : base_(NULL), m_(m), n_(n)
{
	buildMatrix();
}
template <class it_t> Matrix_t <it_t>::Matrix_t(const Matrix_t& M) {
	m_ = M.m_;
	n_ = M.n_;
	buildMatrix();
	for (int i = 0; i < n_*m_; i++)
		base_[i] = M.base_[i];
}
template <class it_t> Matrix_t <it_t> :: ~Matrix_t(void)
{
	removeMatrix();
}
template <class it_t> void Matrix_t <it_t> ::buildMatrix(void)
{
	try {
		base_ = new it_t[m_*n_];//Crea un vector de m*n elementos
	}
	
	catch (std::bad_alloc &){
		std::cerr << "Error creando matriz." <<std::endl;
		throw;
	}
}
template <class it_t> void Matrix_t <it_t> ::buildMatrix(sz_t m, sz_t n) 
{	
	m_ = m;
	n_ = n;

	try {
		base_ = new it_t[m_*n_];//Crea un vector de m*n elementos
	}

	catch (std::bad_alloc &){
		std::cerr << "Error creando matriz." << std::endl;
		throw;
	}
}
template <class it_t> void Matrix_t <it_t> ::removeMatrix(void)
{
	if (base_ != NULL){
		delete[] base_;	// Libera la memoria previamente reservada para la matriz.
		base_ = NULL;		// Asigna NULL al puntero.
	}

	m_ = 0;
	n_ = 0;
}
template <class it_t> it_t& Matrix_t <it_t> ::elemento(ix_t i, ix_t j)
{
	if ((i<1) || (i>nfilas()) || (j<1) || (j>ncolumnas())){
		std::cerr << "Error accediendo a matriz" << std::endl;
		throw 2;
	}
	return base_[(i - 1)*n_ + j - 1];
}
template <class it_t> it_t& Matrix_t <it_t> ::elemento(ix_t i, ix_t j) const
{
	if ((i<1) || (i>nfilas()) || (j<1) || (j>ncolumnas())){
		std::cerr << "Error accediendo a matriz" << std::endl;
		throw 2;
	}
	return base_[(i - 1)*n_ + j - 1];
}
template <class it_t> sz_t Matrix_t <it_t> ::nfilas(void) const
{
	return m_;
}
template <class it_t> sz_t Matrix_t <it_t> ::ncolumnas(void) const
{
	return n_;
}
template <class it_t> void Matrix_t <it_t> ::read(std::istream& is)
{
	int m, n;
	is >> m >> n;

	m_ = m;
	n_ = n;
	buildMatrix();

	const int sz = m*n;

	for (int i = 0; i<sz; i++)
		is >> base_[i];

}
template <class it_t> void Matrix_t <it_t> ::write(std::ostream& os)
{
	char aux[80];

	//sprintf(aux, " %10d  %10d ", m_, n_);
//	os << aux << endl;
	
	for (int i = 1; i <= m_; i++){
		for (int j = 1; j <= n_; j++){
			//sprintf(aux, " %10.6lf ", elemento(i, j));
			os << "    "<< elemento(i,j)<<"    ";
		}
		os << endl;
	}
}
template <class it_t> int Matrix_t <it_t> ::signo(ix_t i, ix_t j){
	return pow(-1, (i + j));
}
template <class it_t> void Matrix_t <it_t> ::subMatriz(ix_t i, ix_t j, Matrix_t& SM)
{

	ix_t inx_i = 0;
	ix_t inx_j = 0;
	int k, l;

	for (k = 1; k <= m_; k++) {
		if (i != k) {
			inx_i++;
			inx_j = 0;
			for (l = 1; l <= n_; l++) {
				if (j != l) {
					inx_j++;
					SM.elemento(inx_i, inx_j) = elemento(k, l);
				}
			}
		}
	}
}
template <class it_t> it_t Matrix_t <it_t> ::determinante(int &c)
{
	it_t det = 0;
	int i, j;

	if (n_ + m_ == 2) {
		det = elemento(1, 1);
		c++;
	}
	else {
		Matrix_t SM(m_ - 1, n_ - 1);
		for (i = 1; i <= m_; i++) {
			subMatriz(i, 1, SM);
			det = det + elemento(i, 1)*signo(i, 1)*SM.determinante(c);
		}
	}

	return det;
}
template <class it_t> Matrix_t <it_t> Matrix_t <it_t> ::operator+ (const Matrix_t <it_t> & M) const  {
	
	Matrix_t <it_t> suma(m_,n_);

	if (m_ != M.m_ || n_ != M.n_) {
		std::cerr << "No es posible sumar matrices" << endl;
		throw 3;
	}
	else{
		for (int i = 1; i <= m_; i++) {
			for (int j = 1; j <= n_; j++) {
				suma.elemento(i, j) = elemento(i, j) + M.elemento(i, j);
			}
		}
	}
	return suma;
}
template <class it_t> Matrix_t <it_t> &   Matrix_t <it_t> ::operator = (const Matrix_t <it_t> & M) {
	
	removeMatrix();
	m_ = M.m_;
	n_ = M.n_;
	buildMatrix();
	
	for (int i = 1; i <= m_; i++)
		for (int j = 1; j<=n_; j++)
			elemento(i,j) = M.elemento(i,j);
	return *this;
}
template <class it_t> Matrix_t <it_t> Matrix_t <it_t> ::operator - (const Matrix_t <it_t> & M) const {
	Matrix_t <it_t> resta(m_, n_);

	if (m_ != M.m_ || n_ != M.n_) {
		std::cerr << "No es posible restar matrices" << endl;
		throw 3;
	}
	else{
		for (int i = 1; i <= m_; i++) {
			for (int j = 1; j <= n_; j++) {
				resta.elemento(i, j) = elemento(i, j) - M.elemento(i, j);
			}
		}
	}
	return resta;

}
template <class it_t> bool  Matrix_t <it_t> ::operator== (const Matrix_t <it_t> & M) const {
	bool igual = true;
	if (m_ != M.m_ || n_ != M.n_) {
		std::cerr << "No es posible comparar matrices" << endl;
		throw 3;
	}
	else{
		for (int i = 1; i <= m_; i++) {
			for (int j = 1; j <= n_; j++) {
				if (elemento(i, j) != M.elemento(i, j))
					igual = false;
			}
		}
	}
	return igual;

}
template <class it_t> bool  Matrix_t <it_t> ::operator!= (const Matrix_t <it_t> & M) const {
	bool igual = true;
	if (m_ != M.m_ || n_ != M.n_) {
		std::cerr << "No es posible comparar matrices" << endl;
		throw 3;
	}
	else{
		for (int i = 1; i <= m_; i++) {
			for (int j = 1; j <= n_; j++) {
				if (elemento(i, j) != M.elemento(i, j))
					igual = false;
			}
		}
	}
	return (!igual);

}
