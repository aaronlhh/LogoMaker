//
//  Cursor.cpp
//  text_input
//
//  Created by Aaron Lin on 4/10/21.
//

#include "Cursor.hpp"


Cursor::Cursor(){
    sf::Vector2f vec(5, 50);
    cursor.setFillColor(sf::Color::White);
    cursor.setOutlineThickness(1);
    cursor.setSize(vec);
    blinkOn = false;
    clock.restart();
}

Cursor::Cursor(sf::Vector2f& size){
    cursor.setFillColor(sf::Color::White);
    cursor.setOutlineThickness(1);
    cursor.setSize(size);
    blinkOn = false;
    clock.restart();
}



void Cursor::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(cursor);
}


void Cursor::addEventHandler(sf::RenderWindow& window, sf::Event event){
    
}


void Cursor::update(){
    // switching colors, white <-> transparent
    if(clock.getElapsedTime() >= sf::milliseconds(500)){
        clock.restart();
        
        if(!blinkOn){
            cursor.setFillColor(sf::Color::White);
        }else{
            cursor.setFillColor(sf::Color::Transparent);
            cursor.setOutlineColor(sf::Color::Transparent);
        }
        
        toggleBlinkState();
    }
}


void Cursor::toggleBlinkState(){
    // flip boolean
    // switching states
    
    if(blinkOn)
        blinkOn = false;
    else
        blinkOn = true;
}


void Cursor::setPosition(float x, float y){
    cursor.setPosition(x, y);
}

void Cursor::setSize(float x, float y){
    cursor.setSize(sf::Vector2f(x,y));
}


sf::Vector2f Cursor::getSize(){
    return cursor.getSize();
}
