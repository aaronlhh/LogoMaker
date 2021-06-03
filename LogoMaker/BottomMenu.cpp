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
    
    Slider textRotate = Slider("Text Rotate", 360);
    sliderIndex[States::TEXT_ROTATE] = index++;
    sliders.push_back(textRotate);
    
    Slider shadowRotate = Slider("Shadow Rotate", 360);
    sliderIndex[States::SHADOW_ROTATE] = index++;
    sliders.push_back(shadowRotate);
    
    Slider textOpa = Slider("Text Opacity", 255, 255);
    sliderIndex[States::TEXT_OPACITY] = index++;
    sliders.push_back(textOpa);
    
    Slider fontSize = Slider("Font Size", 100, 35);
    sliderIndex[States::FONT_SIZE] = index++;
    sliders.push_back(fontSize);
    
    Slider skew = Slider("Skew", 100, 15);
    sliderIndex[States::SKEW] = index++;
    sliders.push_back(skew);

    Slider shadowOpa = Slider("Shadow Opacity", 255, 127);
    sliderIndex[States::SHADOW_OPACITY] = index++;
    sliders.push_back(shadowOpa);

    Slider backgroundOpa = Slider("Background Opacity", 255, 255);
    sliderIndex[States::SKEW] = index++;
    sliders.push_back(backgroundOpa);

    Slider xAxis = Slider("Text X-Axis", 1000, 239);
    sliderIndex[States::TEXT_X_AXIS] = index++;
    sliders.push_back(xAxis);

    Slider yAxis = Slider("Text Y-Axis", 1000, 164);
    sliderIndex[States::TEXT_Y_AXIS] = index++;
    sliders.push_back(yAxis);

    Slider shadowXAxis = Slider("Shadow X-Axis", 1000, 509);
    sliderIndex[States::SHADOW_X_AXIS] = index++;
    sliders.push_back(shadowXAxis);

    Slider ShadowYAxis = Slider("Shadow Y-Axis", 1000, 172);
    sliderIndex[States::SHADOW_Y_AXIS] = index++;
    sliders.push_back(ShadowYAxis);


    
    // setup positions
    setPosition(40, States::WINDOW_HEIGHT/2);
}


void BottomMenu::setPosition(float x, float y){
    int vertPadding = 30;
    int horiPadding = 60;
    
    inputBox.setPosition(x, y);
    
    fontList.setPosition(x, y + inputBox.getGlobalBounds().height + 10);
    bar.setPosition(fontList.getPosition().x + fontList.getGlobalBounds().width + horiPadding*2,
                    fontList.getPosition().y + 30);
    
    
    sliders.at(0).setPosition(x, bar.getGlobalBounds().top + bar.getGlobalBounds().height + 20);
    sliders.at(1).setPosition(sliders.at(0).getPosition().x + sliders.at(0).getGlobalBounds().width + horiPadding,
                              sliders.at(0).getPosition().y );
    
    
    sliders.at(2).setPosition(x, sliders.at(0).getPosition().y + sliders.at(0).getGlobalBounds().height + vertPadding);
    sliders.at(3).setPosition(sliders.at(2).getPosition().x + sliders.at(2).getGlobalBounds().width + horiPadding,
                              sliders.at(2).getPosition().y);
    sliders.at(4).setPosition(sliders.at(3).getPosition().x + sliders.at(3).getGlobalBounds().width + horiPadding,
                              sliders.at(2).getPosition().y);
    
    
    sliders.at(5).setPosition(x,
                              sliders.at(2).getPosition().y + sliders.at(2).getGlobalBounds().height + vertPadding);
    sliders.at(6).setPosition(sliders.at(5).getPosition().x + sliders.at(5).getGlobalBounds().width + horiPadding,
                              sliders.at(5).getPosition().y);
    
    
    sliders.at(7).setPosition(x,
                              sliders.at(6).getPosition().y + sliders.at(6).getGlobalBounds().height + vertPadding);
    sliders.at(8).setPosition(x,
                              sliders.at(7).getPosition().y + sliders.at(7).getGlobalBounds().height + vertPadding);
    sliders.at(9).setPosition(x,
                              sliders.at(8).getPosition().y + sliders.at(8).getGlobalBounds().height + vertPadding);
    sliders.at(10).setPosition(x,
                              sliders.at(9).getPosition().y + sliders.at(9).getGlobalBounds().height + vertPadding);
}


int BottomMenu::getSliderValue(States::sliderType key){
    int index = sliderIndex[key];
    Slider& slider = sliders.at(index);
    return slider.getCurVal();
}

string BottomMenu::getLogoText(){
    return inputBox.getString();
}

sf::Color BottomMenu::getTextColor(){
    return bar.getTextColor();
}

sf::Color BottomMenu::getBackGroundColor(){
    return bar.getBackGroundColor();
}

sf::Font& BottomMenu::getFont(){
    return States::getFont(fontList.getFont(), fontList.getStyle());
}

void BottomMenu::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    for(int i = 0; i < sliders.size(); i ++){
        window.draw(sliders.at(i));
    }
    window.draw(inputBox);
    window.draw(bar);
    window.draw(fontList);
}



void BottomMenu::addEventHandler(sf::RenderWindow& window, sf::Event event){
    inputBox.addEventHandler(window, event);
    bar.addEventHandler(window, event);
    fontList.addEventHandler(window, event);
    for(int i = 0; i < sliders.size(); i ++){
        sliders.at(i).addEventHandler(window, event);
    }
    
}



void BottomMenu::update(){
    inputBox.update();
    fontList.update();
}
