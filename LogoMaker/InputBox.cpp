//
//  InputBox.cpp
//  dropdown_menu
//
//  Created by Aaron Lin on 4/27/21.
//

#include "InputBox.hpp"


InputBox::InputBox(string msg, sf::Vector2f vec, sf::Color color){
    
    box.setSize(vec);
    box.setOutlineThickness(1);
    box.setOutlineColor(color);
    box.setFillColor(sf::Color::Transparent);
    
    if(!States::isFontLoaded(States::ARIAL)){
        States::setFontLoad(States::ARIAL, true);
    }
    text.setFont(States::getFont(States::ARIAL, States::REGULAR));
    text.setString(msg);
    text.setFillColor(color);
    text.setCharacterSize(vec.y/2);
    text.setPosition(getPosition().x + box.getGlobalBounds().width/2 - text.getGlobalBounds().width/2,
                     getPosition().y + box.getGlobalBounds().height/2 - text.getGlobalBounds().height/1.5);
    
}


InputBox::InputBox(string msg, sf::Vector2f vec)
: InputBox(msg, vec, sf::Color::White){
    
}


InputBox::InputBox(string msg)
: InputBox(msg, {250,50}, sf::Color::White){
    
}


InputBox::InputBox()
: InputBox("Something", {250, 50}, sf::Color::White){
    
}


void InputBox::setText(string msg){
    text.setString(msg);
    setPosition(getPosition().x, getPosition().y);
}

string InputBox::getText(){
    return text.getString();
}

sf::FloatRect InputBox::getGlobalBounds(){
    return box.getGlobalBounds();
}


void InputBox::setSize(float x, float y){
    box.setSize({x,y});
    text.setCharacterSize(y/2);
}


void InputBox::setPosition(float x, float y){
    box.setPosition(x, y);
    text.setPosition(x + box.getGlobalBounds().width/2 - text.getGlobalBounds().width/2,
                     y + box.getGlobalBounds().height/2 - text.getGlobalBounds().height/1.5);
}

void InputBox::setFillColor(sf::Color color){
    box.setFillColor(color);
}

void InputBox::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(box);
    window.draw(text);
}
