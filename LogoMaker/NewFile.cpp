//
//  NewFile.cpp
//  LogoMaker
//
//  Created by Aaron Lin on 6/8/21.
//

#include "NewFile.hpp"


NewFile::NewFile(){
    input.setLabel("Enter FileName to Save: ");
    input.setLength(500);
    input.setSize(500, 50);
    input.setLabelSize(30);
    button.setText("Confirm");
    button.setPosition(input.getPosition().x + input.getGlobalBounds().width/2 - button.getGlobalBounds().width/3*2,
                       input.getPosition().y + 250);
}


string NewFile::run(){
    window.create(sf::VideoMode({800,500}), "FileName prompt");
    input.setPosition(100,100);
    string result;
    while(window.isOpen()){
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                result = "NULL";
                window.close();
            }else if(MouseEvents<InputBox>::mouseClicked(button, window)){
                result = input.getString();
                window.close();
            }
            input.addEventHandler(window, event);
        }
        input.update();
        window.clear();
        window.draw(input);
        window.draw(button);
        window.display();
    }
    return result;
}
