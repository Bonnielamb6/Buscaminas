#pragma once
#include "Grid.h"
#include "boton.h"

class GridBuscaMinas : public Grid
{
private:
	boton** matrizJuego;//matriz que tendra las imagenes
	int numeroMinas;//cantidad de minas en el grid
	int numBotonesFaltantes;//botones faltantes que no tienen minas
	int estado;//0 si esta jugando, 1 si gana, -1 si pierde
	boton* posicionesMinas;//arreglo de botones con bombas
public:
	GridBuscaMinas(int filas,int columnas,int numeroMinas);
	~GridBuscaMinas();
	void llenarMatrizJuego();
	void agregarMinas();
	void actualizarNumMinasAlrededor();//aqui usare el arreglo de punteros para actualizar la tabla completa
	void sumarValoresAlrededorMina(int fila, int columna);
	//void obtenerBotonesMinas();
	void presionarBoton(int fila, int columna);
	void ponerBanera(int fila, int columna);
	int getEstado();
};

