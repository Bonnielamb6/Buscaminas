#include "GridBuscaMinas.h"
#include <math.h>
#include <cstdlib>

GridBuscaMinas::GridBuscaMinas(int filas, int columnas, int numeroMinas) :Grid(filas, columnas), numeroMinas(numeroMinas)
{
	setFilas(filas);
	setColumnas(columnas);
	this->matrizJuego = nullptr;
	this->numeroMinas = numeroMinas;
	this->estado = 0;
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

			posicionesMinas[minasGeneradas].setFila(tempFila);	//Agrego un boton con bomba a mi arreglo de botones con bombas con el valor de su fila y columna
			posicionesMinas[minasGeneradas].setColumna(tempColumna);
			minasGeneradas++;
		}
		
	}
}

void GridBuscaMinas::actualizarNumMinasAlrededor()
{
	int i = 0;
	while (i<numeroMinas)
	{
		sumarValoresAlrededorMina(posicionesMinas[i].getFila(), posicionesMinas[i].getColumna());
		i++;
	}
	/*for (int i = 0; i < filas; i++) 
	{
		for (int j = 0; j < columnas; j++)
		{
			matrizJuego[i][j].getValor = determinarCantidadMinasAlrededor(i,j);
		}
	}*/
}

int GridBuscaMinas::sumarValoresAlrededorMina(int filaTemp, int columnaTemp)
{
	matrizJuego[filaTemp--][columnaTemp].sumarUno();
	matrizJuego[filaTemp][columnaTemp--].sumarUno();
	matrizJuego[filaTemp--][columnaTemp--].sumarUno();
	matrizJuego[filaTemp++][columnaTemp].sumarUno();
	matrizJuego[filaTemp][columnaTemp++].sumarUno();
	matrizJuego[filaTemp++][columnaTemp++].sumarUno();
	matrizJuego[filaTemp--][columnaTemp++].sumarUno();
	matrizJuego[filaTemp++][columnaTemp--].sumarUno();
}

void GridBuscaMinas::presionarBoton(int fila, int columna) //click izquierdo
{
	if (matrizJuego[fila][columna].getEstado() != 1)
	{
		if (matrizJuego[fila][columna].getValor() == 0)//si no tiene ningun valor, entonces aplicar el algoritmo de flood
		{

		}
		if (matrizJuego[fila][columna].getValor() > 0) //si tiene un valor mayor a 0, o sea que hay una mina cerca, entonces solo mostrar ese boton
		{

		}
		if (matrizJuego[fila][columna].getMina() == 1)
		{
			estado = -1;
		}
	}
}

void GridBuscaMinas::ponerBanera(int fila, int columna)//click derecho
{
	matrizJuego[fila][columna].setEstado(1);
}

int GridBuscaMinas::getEstado()
{
	return estado;
}


