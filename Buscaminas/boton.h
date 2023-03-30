#pragma once
class boton
{
private:
	int mina;//0 no es una mina el boton, 1 si es una mina el boton
	int valor;//cuantas minas tiene alrededor,0 no tiene minas alrededor, 1 tiene 1 mina n tiene n minas
	int fila;//en que fila esta
	int columna;//en que columna esta
	int activa;//1 aun se puede presionar, 0 ya fue usada
	int bandera;//1 tiene la bandera puesta, 0 no tiene bandera puesta
public:
	boton();
	void activarMina();
	int getMina();
	void setValor(int valor);
	int getValor();
	void setFila(int fila);
	int getFila();
	void setColumna(int columna);
	int getColumna();
	void setActiva(int activa);
	int getActiva();
	void activarBandera();
	int getBandera();
};

