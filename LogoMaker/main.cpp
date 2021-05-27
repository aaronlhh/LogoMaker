//
//  main.cpp
//  LogoMaker
//
//  Created by Aaron Lin on 5/27/21.
//

#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(1200, 1000), "dropdown");
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }
        window.clear();
        window.display();
    }
}
