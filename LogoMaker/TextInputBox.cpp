//
//  TextInputBox.cpp
//  text_input
//
//  Created by Aaron Lin on 4/7/21.
//

#include "TextInputBox.hpp"


TextInputBox::TextInputBox()
: TextInputBox(1300, 50, sf::Color::White){
    
}

TextInputBox::TextInputBox(const sf::Vector2f& size)
: TextInputBox(size.x, size.y, sf::Color::White){
    
}

TextInputBox::TextInputBox(sf::Color color)
: TextInputBox(1300, 50, color){
    
}

TextInputBox::TextInputBox(float width, float height, sf::Color color)
: sf::RectangleShape({width, height}){
    setOutlineThickness(1);
    setOutlineColor(sf::Color::White);
    setFillColor(sf::Color::Transparent);
}



