#include "GridBuscaMinas.h"
#include <math.h>
#include <cstdlib>

GridBuscaMinas::GridBuscaMinas(int filas, int columnas, int numeroMinas) :Grid(filas, columnas), numeroMinas(numeroMinas)
{
	setFilas(filas);
	setColumnas(columnas);
	this->matrizJuego = nullptr;
	this->numeroMinas = numeroMinas;
	this->ganar = 0;
	this->perder = 0;
	this->jugando = 1;
	llenarMatriz();
	llenarMatrizBack();
}

GridBuscaMinas::~GridBuscaMinas()
{
	for (int i = 0; i < this->getFilas(); i++) {
		delete[] matrizJuego[i];
	}
	delete[] matrizJuego;
}

void GridBuscaMinas::llenarMatrizJuego()
{
	for (int i = 0; i < filas; i++) 
	{
		for (int j = 0; j < columnas; j++) 
		{
			
		}
	}
}

void GridBuscaMinas::agregarMinas()
{
	int minasGeneradas = 0;
	while (minasGeneradas != numeroMinas) {
		int tempFila = rand() % filas;
		int tempColumna = rand() % columnas;
		if (matrizJuego[tempFila][tempColumna].getMina() == 0)
		{
			matrizJuego[tempFila][tempColumna].activarMina();
			matrizJuego[tempFila][tempColumna].setValor(-1);
			minasGeneradas++;
		}
		
	}
}

void GridBuscaMinas::actualizarNumMinasAlrededor()
{
	for (int i = 0; i < filas; i++) 
	{
		for (int j = 0; j < columnas; j++)
		{
			matrizJuego[i][j].getValor = determinarCantidadMinasAlrededor(i,j);
		}
	}
}

int GridBuscaMinas::determinarCantidadMinasAlrededor(int fila, int columna)
{
	valor = 0;
	if (matrizJuego[fila][columna].getMina() == 1)
	{
		valor++;
	}
	if (matrizJuego[fila--][columna].getMina() == 1)
	{
		valor++;
	}
	if (matrizJuego[fila][columna--].getMina() == 1)
	{
		valor++;
	}
	if (matrizJuego[fila--][columna--].getMina() == 1)
	{
		valor++;
	}
	if (matrizJuego[fila++][columna].getMina() == 1)
	{
		valor++;
	}
	if (matrizJuego[fila][columna++].getMina() == 1)
	{
		valor++;
	}
	if (matrizJuego[fila++][columna++].getMina() == 1)
	{
		valor++;
	}
	if (matrizJuego[fila++][columna--].getMina() == 1)
	{
		valor++;
	}
	if (matrizJuego[fila--][columna++].getMina() == 1)
	{
		valor++;
	}
	return valor;
}

void GridBuscaMinas::presionarBoton(int fila, int columna)
{
	if (matrizJuego[fila][columna].getBandera == 0) 
	{
		if (matrizJuego[fila][columna].getValor() == 0)//si no tiene ningun valor, entonces aplicar el algoritmo de flood
		{

		}
		if (matrizJuego[fila][columna].getValor() > 0) //si tiene un valor mayor a 0, o sea que hay una mina cerca, entonces solo mostrar ese boton
		{

		}
		if (matrizJuego[fila][columna].getMina() == 1)
		{
			perder = 1;
			jugando = 0;
		}
	}
}

void GridBuscaMinas::ponerBanera(int fila, int columna)
{
	matrizJuego[fila][columna].
}


int GridBuscaMinas::estadoJuego()
{
	int estado = 0;

	if (jugando == 1)
	{
		estado = 1;
	}
	if (perder == 1)
	{
		estado = 0;
	}
	if (ganar == 1)
	{
		estado = 0;
	}
	return estado;//si regresamos 0 entonces se desactiva todo, si regresamos 1 entonces se puede seguir jugando
}

