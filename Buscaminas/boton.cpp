#include "boton.h"

boton::boton()
{
	this->mina = 0;
	this->valor = 0;
	this->fila = 0;
	this->columna = 0;
	this->estado = 0;
}

void boton::activarMina()
{
	mina = 1;
	valor = -1;
}

int boton::getMina()
{
	return mina;
}

void boton::setValor(int valor)
{
	this->valor = valor;
}

int boton::getValor()
{
	return valor;
}

void boton::sumarUno()
{
	if (getMina() != 1) {
		valor++;
	}
	
}

void boton::setFila(int fila)
{
	this->fila = fila;
}

int boton::getFila()
{
	return fila;
}

void boton::setColumna(int columna)
{
	this->columna = columna;
}

int boton::getColumna()
{
	return columna;
}

void boton::setEstado(int estado)
{
	this->estado = estado;
}

int boton::getEstado()
{
	return estado;
}


