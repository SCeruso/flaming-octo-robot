#pragma once
#include<iostream>
#include<math.h>
#include<stdio.h>

typedef unsigned it_t; 				//Tipo de elemento de la tabla

typedef struct {
	unsigned v; 				//Valor del elemento
	unsigned w; 				//Peso del elemento
}N_t;

class Mochila_t {

private:
	unsigned 	n_; 			//Número de elementos
	unsigned 	Cap_;			//Capacidad de la mochila
	it_t*		V_; 			//Matriz de valores
	N_t*		N_; 			//Vector valor-peso
public:
	Mochila_t(void);			//Constructor por defecto
	Mochila_t(unsigned a, unsigned b);	//Constructor
	~Mochila_t(void);			//Destructor
private:
	void delete_Mochila(void);		//Libera memoria
	void build_Mochila(void);		//Reserva memoria
public:
	void read(std::istream& is);		//Función lectura
	void write(std::ostream& os);		//Función escritura
	void create_V(void);			//Crea la tabla
	it_t& elemento(int i, int j); 		//Devuelve el elemento que está en la posición (i,j) en la tabla
};
