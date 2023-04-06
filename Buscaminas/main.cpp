#include <iostream>
#include <SFML/Graphics.hpp>
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include "GridBuscaMinas.h"
#include "Grid.h"
#include "TextBox.h"
#include "Button.h"
/*RECORDAR QUE TODO LO QUE PONGO AQUI DEBERE DE CAMBIARLO A UN ARCHIVO .RUN PARA SU MEJOR USO*/


int main()
{
    //GridBuscaMinas* juego = new GridBuscaMinas(10, 10, 10);
    sf::RenderWindow window;

    sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445, (sf::VideoMode::getDesktopMode().height / 2) - 480);

    window.create(sf::VideoMode(900, 900), "Buscaminas", sf::Style::Titlebar | sf::Style::Close);
    window.setPosition(centerWindow);
    
    window.setKeyRepeatEnabled(true);

    sf::Texture textura;
    textura.loadFromFile("images/tiles.jpg");
    sf::Sprite casilla(textura);
    
    sf::Font arial;
    arial.loadFromFile("arial.ttf");
    TextBox textbox1(15,sf::Color::White,false);
    textbox1.setFont(arial);
    textbox1.setPosition({ 5,5 });
    textbox1.setLimit(true, 10);
    
    Button btn1("Click me", { 200,50 }, 20, sf::Color::Green, sf::Color::Black);
    btn1.setPosition({ 300,5 });
    /*
    PONER LOS VALORES CORRECTOS DE FILAS Y COLUMNAS PARA LAS MATRICES
    PONERLE LAS MINAS Y VALORES A LAS MATRICES
    DIBUJAR LAS CASILLAS
    JUGAR
    ACTUALIZAR LOS SPRITES CADA VEZ QUE PRESIONA UN BOTON
    */
    
    
    //main loop
    while (window.isOpen())
    {
        sf::Event event;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
            textbox1.setSelected(true);

        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            textbox1.setSelected(false);
        }
        //Loop para los eventos
        while (window.pollEvent(event))
        {
            switch (event.type) {
            
                case sf::Event::Closed:
                    window.close();

                case sf::Event::TextEntered:
                    textbox1.typedOn(event);
                    break;
                case sf::Event::MouseMoved:
                    if (btn1.isMouseOver(window)) {
                        btn1.setBackColor(sf::Color::White);
                    }else{
                        btn1.setBackColor(sf::Color::Green);
                    }
                    break;
            }
            
        }

        window.clear();
        textbox1.drawTo(window);
        btn1.drawTo(window);
        window.display();
    }
}



