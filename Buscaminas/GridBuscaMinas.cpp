#include "GridBuscaMinas.h"
#include <math.h>
#include <cstdlib>

GridBuscaMinas::GridBuscaMinas()
{
	matrizJuego = nullptr;
	numeroMinas = 0;
	numBotonesFaltantes = 0;
	estado = -2;
	posicionesMinas = nullptr;
}

GridBuscaMinas::GridBuscaMinas(int filas, int columnas, int numeroMinas) :Grid(filas, columnas), numeroMinas(numeroMinas)
{
	this->filas = filas;
	this->columnas = columnas;
	this->matrizJuego = nullptr;
	this->numeroMinas = numeroMinas;
	this->estado = 0;
	this->posicionesMinas = new boton [numeroMinas];
	llenarMatriz();
	llenarMatrizJuego();
	agregarMinas();
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
	this->matrizJuego = new boton* [this->filas];
	for (int i = 0; i < this->filas; i++) {
		this->matrizJuego[i] = new boton[this->columnas]; // crear un arreglo de enteros para cada fila
		
	}
	for (int i = 0; i < this->filas; i++) {
		for (int j = 0; j < this->columnas; j++) {
			this->matrizJuego[i][j].setFila(i);
			this->matrizJuego[i][j].setColumna(j);
			this->matrizJuego[i][j].setEstado(0);
			this->matrizJuego[i][j].setValor(0);
			
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
			

			posicionesMinas[minasGeneradas].setFila(tempFila);	//Agrego un boton con bomba a mi arreglo de botones con bombas con el valor de su fila y columna
			posicionesMinas[minasGeneradas].setColumna(tempColumna);
			minasGeneradas++;
			sumarValoresAlrededorMina(tempFila,tempColumna);
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

void GridBuscaMinas::sumarValoresAlrededorMina(int filaTemp, int columnaTemp)
{
	int fila = filaTemp;
	int columna = columnaTemp;
	if (!(fila - 1 < 0)) {
		matrizJuego[fila - 1][columna].sumarUno();
	}
	if (!(columna - 1 < 0)) {
		matrizJuego[fila][columna - 1].sumarUno();
	}
	if (!(fila - 1< 0) && !(columna - 1 < 0)) {
		matrizJuego[fila - 1][columna - 1].sumarUno();
	}
	if (!(fila + 1 > filas - 1)) {
		matrizJuego[fila + 1][columna].sumarUno();
	}
	if (!(columna + 1 > columnas - 1)) {
		matrizJuego[fila][columna + 1].sumarUno();
	}
	if (!(fila + 1 > filas - 1) && !(columna + 1> columnas - 1)) {
		matrizJuego[fila + 1][columna + 1].sumarUno();
	}
	if (!(fila - 1 < 0) && !(columna + 1 > columnas - 1)) {
		matrizJuego[fila - 1][columna + 1].sumarUno();
	}
	if (!(fila + 1 > filas - 1) && !(columna - 1 < 0)) {
		matrizJuego[fila + 1][columna - 1].sumarUno();
	}
	
}

int GridBuscaMinas::obtenerBotonesFaltantes()
{
	int btnFaltantes = 0;
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			if (matrizJuego[i][j].getEstado() == 0 || matrizJuego[i][j].getEstado() == 1) {
				btnFaltantes++;
			}
		}
	}
	return btnFaltantes;
}

void GridBuscaMinas::presionarBoton(int fila, int columna) //click izquierdo
{
	
	if (matrizJuego[fila][columna].getEstado() != 1)
	{
		if (matrizJuego[fila][columna].getValor() == 0)//si no tiene ningun valor, entonces aplicar el algoritmo de flood
		{
			inundacion(fila, columna); 
			numBotonesFaltantes = obtenerBotonesFaltantes();
		}
		if (matrizJuego[fila][columna].getValor() > 0) //si tiene un valor mayor a 0, o sea que hay una mina cerca, entonces solo mostrar ese boton
		{
			matrizJuego[fila][columna].setEstado(-1);
			numBotonesFaltantes = obtenerBotonesFaltantes();
		}
		if (matrizJuego[fila][columna].getMina() == 1)
		{
			setEstado(-1);
		}
		if (numBotonesFaltantes == numeroMinas) {
			setEstado(1);
		}
		
	}
}

void GridBuscaMinas::ponerBanera(int fila, int columna)//click derecho
{
	if (matrizJuego[fila][columna].getEstado() == 1) {
		matrizJuego[fila][columna].setEstado(0);
	}
	else {
		matrizJuego[fila][columna].setEstado(1);
	}
	
}

int GridBuscaMinas::getEstado()
{
	return estado;
}

void GridBuscaMinas::setEstado(int estado)
{
	this->estado = estado;
}

void GridBuscaMinas::inundacion(int filaTemp, int columnaTemp)
{
	int fila = filaTemp;
	int columna = columnaTemp;
	
	if (matrizJuego[fila][columna].getValor() == 0 && matrizJuego[fila][columna].getEstado() != 1 && matrizJuego[fila][columna].getEstado()!=-1) {
		matrizJuego[fila][columna].setEstado(-1);
		if (!(fila - 1 < 0)) {
			inundacion(fila - 1, columna);
		}
		if (!(columna - 1 < 0)) {
			inundacion(fila, columna - 1);
		}
		if (!(fila - 1 < 0) && !(columna - 1 < 0)) {
			inundacion(fila - 1, columna - 1);
		}
		if (!(fila + 1 > filas - 1)) {
			inundacion(fila + 1, columna);
		}
		if (!(columna + 1 > columnas - 1)) {
			inundacion(fila, columna + 1);
		}
		if (!(fila + 1 > filas - 1) && !(columna + 1 > columnas - 1)) {
			inundacion(fila + 1, columna + 1);
		}
		if (!(fila - 1 < 0) && !(columna + 1 > columnas - 1)) {
			inundacion(fila - 1, columna + 1);
		}
		if (!(fila + 1 > filas - 1) && !(columna - 1 < 0)) {
			inundacion(fila + 1, columna - 1);
		}
		
	}
	else if (matrizJuego[fila][columna].getValor() != 0 && matrizJuego[fila][columna].getValor() != 9 && matrizJuego[fila][columna].getEstado() != 1 && matrizJuego[fila][columna].getEstado() != -1) {
		matrizJuego[fila][columna].setEstado(-1);
	}

}

void GridBuscaMinas::mostrarMinas()
{
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			if (matrizJuego[i][j].getMina() == 1) {
				matrizJuego[i][j].setEstado(-1);
			}
		}
	}
}

