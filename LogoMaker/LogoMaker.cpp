//
//  LogoMaker.cpp
//  LogoMaker
//
//  Created by Aaron Lin on 5/30/21.
//

#include "LogoMaker.hpp"


LogoMaker::LogoMaker(){

    // setup background
    background.setSize({(float)States::WINDOW_WIDTH, (float)States::WINDOW_HEIGHT/2});
    

    update();
    setPosition(40, 0);
}


void LogoMaker::setPosition(float x, float y){
    background.setPosition(0, y);
    menu.setPosition(x, y + background.getGlobalBounds().height);
}



void LogoMaker::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(background);
    window.draw(menu);
    window.draw(text);
    window.draw(shadow);
}


void LogoMaker::addEventHandler(sf::RenderWindow& window, sf::Event event){
    menu.addEventHandler(window, event);
}


void LogoMaker::update(){
    menu.update();
    
    // setup background
    sf::Color backgroundColor = menu.getBackGroundColor();
    backgroundColor.a = menu.getSliderValue(States::BACKGROUND_OPACITY);
    
    background.setFillColor(backgroundColor);
    
    
    // setup text
    sf::Color textColor = menu.getTextColor();
    textColor.a = menu.getSliderValue(States::TEXT_OPACITY);
    text.setString(menu.getLogoText());
    text.setFillColor(textColor);
    text.setCharacterSize(menu.getSliderValue(States::FONT_SIZE));
    text.setFont(menu.getFont());
    text.setPosition(menu.getSliderValue(States::TEXT_X_AXIS) + background.getPosition().x,
                     menu.getSliderValue(States::TEXT_Y_AXIS) + background.getPosition().y);
    text.setOrigin(text.getLocalBounds().width/2,
                   text.getLocalBounds().height/2);
    text.setRotation(menu.getSliderValue(States::TEXT_ROTATE));
    
    
    // setup shadow
    sf::Color shadowColor = sf::Color::White;
    shadowColor.a = menu.getSliderValue(States::SHADOW_OPACITY);
    shadow.setScale(1, (double)menu.getSliderValue(States::SKEW)/100*-1);
    shadow.setCharacterSize(menu.getSliderValue(States::FONT_SIZE));
    shadow.setFillColor(shadowColor);
    shadow.setString(menu.getLogoText());
    shadow.setFont(menu.getFont());
    shadow.setPosition(menu.getSliderValue(States::SHADOW_X_AXIS) + background.getPosition().x,
                       menu.getSliderValue(States::SHADOW_Y_AXIS) + background.getPosition().y);
    shadow.setOrigin(shadow.getLocalBounds().width/2,
                     shadow.getLocalBounds().height/2);
    shadow.setRotation(menu.getSliderValue(States::SHADOW_ROTATE));
    
}
