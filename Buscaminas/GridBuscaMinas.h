#pragma once
#include "Grid.h"
class GridBuscaMinas : public Grid
{
private:
	int** matrizJuego;//matriz que tendra las imagenes
	int numeroMinas;//cantidad de minas en el grid
	int numBotonesFaltantes;//botones faltantes que no tienen minas
	int ganar;//1 si gana,0 si aun no se sabe
	int perder;//1 si pierde, 0 si aun no se sabe
	int jugando;//1 si esta jugando,0 si ya gano o perdio, cuando este en 0 se debera deshabilitar todo
public:
	GridBuscaMinas(int filas,int columnas,int numeroMinas);
	~GridBuscaMinas();
	void llenarMatrizBack();
	void agregarMinas();
	void actualizarNumMinasAlrededor();//aqui usare el arreglo de punteros para actualizar la tabla completa
	void obtenerBotonesMinas();
	void presionarBoton();
	void ponerBanera();
};

