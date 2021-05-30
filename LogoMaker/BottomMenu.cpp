//
//  BottomMenu.cpp
//  LogoMaker
//
//  Created by Aaron Lin on 5/27/21.
//

#include "BottomMenu.hpp"




BottomMenu::BottomMenu(){
    
    
    // adding sliders
    int index = 0;
    Slider textOpa = Slider("Text Opacity", 255);
    sliderIndex[States::TEXT_OPACITY] = index++;
    sliders.push_back(textOpa);
    
    Slider fontSize = Slider("Font Size", 100);
    sliderIndex[States::FONT_SIZE] = index++;
    sliders.push_back(fontSize);
    
    Slider skew = Slider("Skew", 100);
    sliderIndex[States::SKEW] = index++;
    sliders.push_back(skew);

    Slider shadowOpa = Slider("Shadow Opacity", 255);
    sliderIndex[States::SHADOW_OPACITY] = index++;
    sliders.push_back(shadowOpa);

    Slider backgroundOpa = Slider("Background Opacity", 255);
    sliderIndex[States::SKEW] = index++;
    sliders.push_back(backgroundOpa);

    Slider xAxis = Slider("Test X-Axis", 1000);
    sliderIndex[States::TEXT_X_AXIS] = index++;
    sliders.push_back(xAxis);

    Slider yAxis = Slider("Test Y-Axis", 1000);
    sliderIndex[States::TEXT_Y_AXIS] = index++;
    sliders.push_back(yAxis);

    Slider shadowXAxis = Slider("Shadow X-Axis", 1000);
    sliderIndex[States::SHADOW_X_AXIS] = index++;
    sliders.push_back(shadowXAxis);

    Slider ShadowYAxis = Slider("Shadow Y-Axis", 1000);
    sliderIndex[States::SHADOW_Y_AXIS] = index++;
    sliders.push_back(ShadowYAxis);

    
    // setup positions
    setPosition(50, States::WINDOW_HEIGHT/2);
}


void BottomMenu::setPosition(float x, float y){
    int vertPadding = 30;
    int horiPadding = 80;
    sliders.at(0).setPosition(x, y);
    sliders.at(1).setPosition(sliders.at(0).getPosition().x + sliders.at(0).getGlobalBounds().width + horiPadding, y);
    sliders.at(2).setPosition(sliders.at(1).getPosition().x + sliders.at(1).getGlobalBounds().width + horiPadding, y);
    sliders.at(3).setPosition(x, y + sliders.at(0).getGlobalBounds().height + vertPadding);
    sliders.at(4).setPosition(sliders.at(3).getPosition().x + sliders.at(3).getGlobalBounds().width + horiPadding,
                                    y + sliders.at(0).getGlobalBounds().height + vertPadding);
    sliders.at(5).setPosition(x, sliders.at(4).getPosition().y + sliders.at(4).getGlobalBounds().height + vertPadding);
    sliders.at(6).setPosition(x, sliders.at(5).getPosition().y + sliders.at(5).getGlobalBounds().height + vertPadding);
    sliders.at(7).setPosition(x, sliders.at(6).getPosition().y + sliders.at(6).getGlobalBounds().height + vertPadding);
    sliders.at(8).setPosition(x, sliders.at(7).getPosition().y + sliders.at(7).getGlobalBounds().height + vertPadding);
}



void BottomMenu::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    for(int i = 0; i < sliders.size(); i ++){
        window.draw(sliders.at(i));
    }
}



void BottomMenu::addEventHandler(sf::RenderWindow& window, sf::Event event){
    for(int i = 0; i < sliders.size(); i ++){
        sliders.at(i).addEventHandler(window, event);
    }
}



void BottomMenu::update(){

}
