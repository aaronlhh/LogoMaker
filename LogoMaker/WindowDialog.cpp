//
//  WindowDialog.cpp
//  LogoMaker
//
//  Created by Aaron Lin on 6/7/21.
//

#include "WindowDialog.hpp"

WindowDialog::WindowDialog(){
   
}


void WindowDialog::run(){
    window.create(sf::VideoMode({1000,1000}), "WindowDialog");
    
    while(window.isOpen()){
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
            
        }
        window.clear();
       
        window.display();
    }
}
