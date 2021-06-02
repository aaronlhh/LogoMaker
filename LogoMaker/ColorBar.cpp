//
//  ColorBar.cpp
//  LogoMaker
//
//  Created by Aaron Lin on 6/2/21.
//

#include "ColorBar.hpp"

ColorBar::ColorBar(){
    // setting texts
    if(!States::isFontLoaded(States::OPENSANS)){
        States::setFontLoad(States::OPENSANS, true);
    }
    textLabel.setFont(States::getFont(States::OPENSANS));
    backgroundLabel.setFont(States::getFont(States::OPENSANS));
    textLabel.setCharacterSize(textColor.getGlobalBounds().height);
    backgroundLabel.setCharacterSize(textColor.getGlobalBounds().height);
    textLabel.setFillColor(sf::Color::White);
    backgroundLabel.setFillColor(sf::Color::White);
    textLabel.setString("Text Color");
    backgroundLabel.setString("Background Color");
    
    // setup initial pos
    setPosition(0, 0);
}


void ColorBar::setPosition(float x, float y){
    int horiPadding = 30;
    textColor.setPosition(x, y);
    textLabel.setPosition(x + textColor.getGlobalBounds().width + horiPadding,
                          y);
    backgroundColor.setPosition(textLabel.getPosition().x + textLabel.getGlobalBounds().width + horiPadding,
                                y);
    backgroundLabel.setPosition(backgroundColor.getGlobalBounds().left + backgroundColor.getGlobalBounds().width + horiPadding ,
                                y);
}



sf::FloatRect ColorBar::getGlobalBounds(){
    sf::FloatRect rect;
    rect.top = textColor.getPosition().y;
    rect.left = textColor.getPosition().x;
    rect.width = textColor.getGlobalBounds().width + textLabel.getGlobalBounds().width + backgroundColor.getGlobalBounds().width + backgroundLabel.getGlobalBounds().width + 30*3;
    rect.height = textColor.getGlobalBounds().height;
    
    return rect;
}



void ColorBar::draw(sf::RenderTarget &window, sf::RenderStates states) const{
    window.draw(textColor);
    window.draw(textLabel);
    window.draw(backgroundColor);
    window.draw(backgroundLabel);
}



void ColorBar::addEventHandler(sf::RenderWindow &window, sf::Event event){
    textColor.addEventHandler(window, event);
    backgroundColor.addEventHandler(window, event);
}
