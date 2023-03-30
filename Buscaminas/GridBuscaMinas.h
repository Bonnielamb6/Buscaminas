#pragma once
#include "Grid.h"
#include "boton.h"

class GridBuscaMinas : public Grid
{
private:
	boton** matrizJuego;//matriz que tendra las imagenes
	int numeroMinas;//cantidad de minas en el grid
	int numBotonesFaltantes;//botones faltantes que no tienen minas
	int ganar;//1 si gana,0 si aun no se sabe
	int perder;//1 si pierde, 0 si aun no se sabe
	int jugando;//1 si esta jugando,0 si ya gano o perdio, cuando este en 0 se debera deshabilitar todo
public:
	GridBuscaMinas(int filas,int columnas,int numeroMinas);
	~GridBuscaMinas();
	void llenarMatrizJuego();
	void agregarMinas();
	void actualizarNumMinasAlrededor();//aqui usare el arreglo de punteros para actualizar la tabla completa
	int determinarCantidadMinasAlrededor(int fila, int columna);
	//void obtenerBotonesMinas();
	void presionarBoton(int fila, int columna);
	void ponerBanera(int fila, int columna);
	int estadoJuego();
};

