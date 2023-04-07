#pragma once
#include <SFML/Graphics.hpp>
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
class boton
{
private:
	int mina;//0 no es una mina el boton, 1 si es una mina el boton
	int valor;//cuantas minas tiene alrededor,0 no tiene minas alrededor, 1 tiene 1 mina n tiene n minas
	int fila;//en que fila esta
	int columna;//en que columna esta
	int estado; //0 inhabilitado, -1 habilitado, 1 bandera     QUIZA 2 INUNDADO
	sf::Sprite imagen;

public:
	boton();
	boton(int fila, int columna, int valor, int estado,sf::Sprite imagen);
	void activarMina();
	int getMina();
	void setValor(int valor);
	int getValor();
	void sumarUno();
	void setFila(int fila);
	int getFila();
	void setColumna(int columna);
	int getColumna();
	void setEstado(int estado);
	int getEstado();
	void setSprite(sf::Sprite imagen);
};

