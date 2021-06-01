//
//  ColorSquare.cpp
//  LogoMaker
//
//  Created by Aaron Lin on 6/1/21.
//

#include "ColorSquare.hpp"


ColorSquare::ColorSquare(sf::Color color){
    setFillColor(color);
    setSize({50,50});
    setOutlineColor(sf::Color::Black);
    setOutlineThickness(1);
}


sf::Color ColorSquare::getColor(){
    return getFillColor();
}


void ColorSquare::setColor(sf::Color color){
    setFillColor(color);
}


