//
//  main.cpp
//  LogoMaker
//
//  Created by Aaron Lin on 5/27/21.
//

#include <SFML/Graphics.hpp>
#include "LogoMaker.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(States::WINDOW_WIDTH, States::WINDOW_HEIGHT), "dropdown");
    LogoMaker menu;
    
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
            menu.addEventHandler(window, event);
        }
        menu.update();
        window.clear();
        window.draw(menu);
        window.display();
        
    }
}
