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
    txtMinas.setLimit(true, 2);

    Button btn1("Jugar", { 100,30 }, 20, sf::Color::White, sf::Color::Black);
    btn1.setPosition({ 450,5 });
    btn1.setFont(arial);
    
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
                    if (btn1.isMouseOver(window)) {
                        std::cout << "You clicked the button"<<std::endl;

                        //SI YA HAY UNO QUE ESTE APUNTANDO A ALGO DIFERENTE DE NULL ENTONCES BORRAR ESE PRIMERO Y VOLVER A DECLARARLO
                        //REVISAR QUE HAYA DATOS EN LOS TEXTBOXES PARA PODER MANDAR LOS VALORES
                        //GridBuscaMinas* juego = new GridBuscaMinas(filas, columnas, bombas);

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
                    
            }
            
        }
        
        window.clear(sf::Color::Black);
        txtFilas.drawTo(window);
        txtColumnas.drawTo(window);
        txtMinas.drawTo(window);
        btn1.drawTo(window);
        window.display();
    }
}



