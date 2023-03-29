#include "GridBuscaMinas.h"

GridBuscaMinas::GridBuscaMinas(int filas, int columnas, int numeroMinas) :Grid(filas, columnas), numeroMinas(numeroMinas)
{
	setFilas(filas);
	setColumnas(columnas);
	this->numeroMinas = numeroMinas;
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

void GridBuscaMinas::llenarMatrizBack()
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
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{

		}
	}
}

