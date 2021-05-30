//
//  Slider.cpp
//  LogoMaker
//
//  Created by Aaron Lin on 5/27/21.
//

#include "Slider.hpp"
#include "MouseEvents.hpp"

Slider::Slider()
:Slider("Slider", 500){
    
}


Slider::Slider(string label)
:Slider(label, 500){
    
}


Slider::Slider(string label, float length){
    // setup font
    if(!States::loadFont){
        if(!States::font.loadFromFile("OpenSans-Bold.ttf")){
            cout << "Unable to find text file\n";
        }
        States::loadFont = true;
    }
    
    // setup label and curVal
    this->label.setFont(States::font);
    this->label.setCharacterSize(States::TEXT_SIZE);
    this->label.setFillColor(sf::Color::White);
    this->label.setString(label+":  ");
    this->curVal.setFont(States::font);
    this->curVal.setCharacterSize(States::TEXT_SIZE);
    this->curVal.setFillColor(sf::Color::White);
    this->curVal.setString("0");
    
    // setup bar
    this->slider.setSize({length, 3});
    this->slider.setFillColor(sf::Color::White);
    
    // setup knob
    this->knob.setRadius(15);
    this->knob.setFillColor(sf::Color::White);
    
    // relative position of knob is initially zero
    relPos = 0;
    
    // initialize position
    setupPosition();
}


void Slider::setupPosition(){
    float padding = 15;
    
    this->slider.setPosition(padding + label.getPosition().x+label.getGlobalBounds().width,
                             label.getPosition().y+label.getCharacterSize()/4*3-slider.getGlobalBounds().height/2);
    
    this->knob.setPosition(slider.getPosition().x + relPos - knob.getRadius(),
                           slider.getPosition().y+slider.getGlobalBounds().height/2-knob.getRadius());
    
    this->curVal.setPosition(slider.getPosition().x + slider.getGlobalBounds().width + padding + 10,
                             label.getPosition().y+3);
    
}

void Slider::setPosition(float x, float y){
    this->label.setPosition(x, y);
    setupPosition();
}

void Slider::setMax(float max){
    this->slider.setSize({max, this->slider.getSize().y});
    setupPosition();
}

void Slider::setLabel(string label){
    this->label.setString(label+": ");
    setupPosition();
}

int Slider::getCurVal(){
    return relPos;
}

string Slider::getLabel(){
    string temp = label.getString();
    return temp;
}

sf::FloatRect Slider::getGlobalBounds(){
    sf::FloatRect rect;
    rect.left = label.getPosition().x;
    rect.top = label.getPosition().y;
    rect.width = label.getGlobalBounds().width + slider.getGlobalBounds().width + curVal.getGlobalBounds().width+40;
    rect.height = label.getCharacterSize();
    return rect;
}

sf::Vector2f Slider::getPosition(){
    return label.getPosition();
}

void Slider::addEventHandler(sf::RenderWindow& window, sf::Event event){
    if(MouseEvents<sf::CircleShape>::draggedOver(knob, window, event)){
        knob.setFillColor(sf::Color::Green);
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        this->relPos = mousePos.x - slider.getPosition().x;
        
        // set boundary
        if(relPos > slider.getSize().x)
            relPos = slider.getSize().x;
        else if(relPos < 0)
            relPos = 0;
        
        // update curVal
        this->curVal.setString(to_string(relPos));
        
        setupPosition();
    }else{
        knob.setFillColor(sf::Color::White);
    }
    
}


void Slider::update(){
    // do nothing
}


void Slider::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(label);
    window.draw(slider);
    window.draw(knob);
    window.draw(curVal);
}
