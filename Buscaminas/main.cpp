#include <iostream>
#include <SFML/Graphics.hpp>
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include "GridBuscaMinas.h"
#include "Grid.h"
#include "TextBox.h"
#include "Button.h"
#include"boton.h"
/*RECORDAR QUE TODO LO QUE PONGO AQUI DEBERE DE CAMBIARLO A UN ARCHIVO .RUN PARA SU MEJOR USO*/


int main()
{
    GridBuscaMinas* juego = new GridBuscaMinas();
    sf::RenderWindow window;

    sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445, (sf::VideoMode::getDesktopMode().height / 2) - 480);

    window.create(sf::VideoMode(900, 900), "Buscaminas", sf::Style::Titlebar | sf::Style::Close);
    window.setPosition(centerWindow);
    
    window.setKeyRepeatEnabled(true);

    //a cada boton de la matriz ponerle una textura y que el boton tenga una variable de tipo textura para que sean independientes
    int casillaAncho = 32;
    boton** inGame = new boton*();

    sf::Texture textura;
    textura.loadFromFile("images/tiles.jpg");
    sf::Sprite casilla(textura);
    
    sf::Font arial;
    arial.loadFromFile("arial.ttf");

    TextBox txtFilas(15, sf::Color::Black, false, sf::Color::White, {100,20});
    txtFilas.setFont(arial);
    txtFilas.setPosition({ 5,5 });
    txtFilas.setLimit(true, 2);
    
    TextBox txtColumnas(15, sf::Color::Black, false, sf::Color::White, {100,20});
    txtColumnas.setFont(arial);
    txtColumnas.setPosition({ 150,5 });
    txtColumnas.setLimit(true, 2);

    TextBox txtMinas(15, sf::Color::Black, false, sf::Color::White, { 100,20 });
    txtMinas.setFont(arial);
    txtMinas.setPosition({ 300,5 });
    txtMinas.setLimit(true, 3);

    Button btn1("Jugar", { 100,30 }, 20, sf::Color::White, sf::Color::Black);
    btn1.setPosition({ 450,5 });
    btn1.setFont(arial);
    
    int filas = 0;
    int columnas = 0;
    int minas = 0;
    
    
    //main loop
    while (window.isOpen())
    {
        sf::Event event;
        sf::Vector2i pos = sf::Mouse::getPosition(window);
        int mouseX = ((pos.x-100) / casillaAncho ) ;
        int mouseY = ((pos.y-100) / casillaAncho ) ;
        
        //Loop para los eventos
        while (window.pollEvent(event))
        {
            switch (event.type) {
            
                case sf::Event::Closed:
                    window.close();

                case sf::Event::TextEntered:
                    txtFilas.typedOn(event);
                    txtColumnas.typedOn(event);
                    txtMinas.typedOn(event);
                    break;
                case sf::Event::MouseMoved: //REVISAR SI EL MOUSE ESTA ENCIMA DEL BOTON Y CAMBIARLE EL COLOR EN ESE CASO
                    if (btn1.isMouseOver(window)) {
                        btn1.setBackColor(sf::Color::Cyan);
                    }else{
                        btn1.setBackColor(sf::Color::White);
                    }
                    break;
                case sf::Event::MouseButtonPressed: //SI SE PRESIONA EL BOTON DE JUGAR ENTONCES TENDRA QUE EMPEZAR LA PARTIDA
                    
                    
                    if (juego->getEstado() == 0) {//EN JUEGO
                        if (((pos.x>100 && pos.y > 100)) && (pos.x<(100+columnas*casillaAncho) && pos.y <(100+filas*casillaAncho))) {
                            if (event.key.code == sf::Mouse::Left) {
                                if (juego->matrizJuego[mouseX][mouseY].getEstado() != 1 && juego->matrizJuego[mouseX][mouseY].getEstado() != -1) {
                                    juego->presionarBoton(mouseX, mouseY);
                                    
                                }
                            }
                            if (event.key.code == sf::Mouse::Right) {
                                if (juego->matrizJuego[mouseX][mouseY].getEstado() == 0) {
                                    juego->ponerBanera(mouseX, mouseY);
                                }
                                else if (juego->matrizJuego[mouseX][mouseY].getEstado() == 1) {
                                    juego->ponerBanera(mouseX, mouseY);
                                }
                            }
                        }
                    }
                    


                    if (btn1.isMouseOver(window)) {
                        
                        if (!(txtFilas.getText() == "") || !(txtColumnas.getText()=="") || !(txtMinas.getText()=="")) {
                            filas = std::stoi(txtFilas.getText());
                            columnas = std::stoi(txtColumnas.getText());
                            minas = std::stoi(txtMinas.getText());
                            juego = new GridBuscaMinas(filas, columnas, minas);
                            inGame = juego->matrizJuego;
                            
                        }
                        
                    }

                    if (txtFilas.isMouseOver(window)) {
                        txtFilas.setSelected(true);
                    }
                    else {
                        txtFilas.setSelected(false);
                    }
                    if (txtColumnas.isMouseOver(window)) {
                        txtColumnas.setSelected(true);
                    }
                    else {
                        txtColumnas.setSelected(false);
                    }
                    if (txtMinas.isMouseOver(window)) {
                        txtMinas.setSelected(true);
                    }
                    else {
                        txtMinas.setSelected(false);
                    } 
                    break;
            }
        }
        if (juego->getEstado() == -1) {//PERDIO
            juego->mostrarMinas();
        }
        if (juego->getEstado() == 1) {//GANO
            juego->mostrarMinas();
        }
        inGame = juego->matrizJuego;
        window.clear(sf::Color::Black);
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                casilla.setTextureRect(sf::IntRect(inGame[i][j].dibujar()*casillaAncho, 0, casillaAncho, casillaAncho));
                casilla.setPosition(i * casillaAncho +100, j * casillaAncho +100);
                window.draw(casilla);
            }
        }
        txtFilas.drawTo(window);
        txtColumnas.drawTo(window);
        txtMinas.drawTo(window);
        btn1.drawTo(window);
        window.display();
    }
}



