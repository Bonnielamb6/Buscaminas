#include "boton.h"

boton::boton()
{
	this->mina = 0;
	this->valor = 0;
	this->fila = 0;
	this->columna = 0;
	this->activa = 1;
	this->bandera = 0;
}

void boton::setMina(int mina)
{
	this->mina = mina;
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

void boton::setActiva(int activa)
{
	this->activa = activa;
}

int boton::getActiva()
{
	return activa;
}

void boton::setBandera()
{
	this->bandera = bandera;
}

int boton::getBandera()
{
	return bandera;
}
