//
//  TextInput.cpp
//  text_input
//
//  Created by Aaron Lin on 4/5/21.
//

#include "TextInput.hpp"

TextInput::TextInput(){
    label.setString("Logo Text:");
    label.setCharacterSize(20);
    
    if(!States::isFontLoaded(States::ARIAL)){
        States::setFontLoad(States::ARIAL, true);
    }
    label.setFont(States::getFont(States::ARIAL, States::REGULAR));
    typing.setSize(textBox.getGlobalBounds().height - textBox.getOutlineThickness()*4);
    
    // setup positions
    setPosition(label.getPosition().x, label.getPosition().y);
}

sf::FloatRect TextInput::getGlobalBounds(){
    sf::FloatRect rect;
    rect.top = label.getPosition().y;
    rect.left = label.getPosition().x;
    rect.width = textBox.getGlobalBounds().width;
    rect.height = textBox.getGlobalBounds().height + label.getCharacterSize() + 15;
    return rect;
}


string TextInput::getLabel(){
    string temp = "";
    temp += label.getString();
    return temp;
}


string TextInput::getString(){
    return typing.getString();
}



void TextInput::setLabel(string word){
    label.setString(word);void setPosition(float x, float y);
}

void TextInput::setLabelSize(int size){
    label.setCharacterSize(size);
    setPosition(label.getPosition().x, label.getPosition().y);
}

void TextInput::setPosition(float x, float y){
    label.setPosition(x, y);
    textBox.setPosition(x, label.getPosition().y + label.getGlobalBounds().height + 15);
    typing.setPosition(x + textBox.getOutlineThickness(),
                       textBox.getPosition().y + textBox.getOutlineThickness()/2);
}

void TextInput::setLength(float len){
    textBox.setSize({len, textBox.getSize().y});
    setPosition(label.getPosition().x, label.getPosition().y);
}

void TextInput::setSize(float x, float y){
    textBox.setSize({x, y});
    setPosition(label.getPosition().x, label.getPosition().y);
}

void TextInput::setText(string text){
    typing.setText(text);
}


void TextInput::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(textBox);
    window.draw(typing);
    window.draw(label);
}

// from EventHandler
void TextInput::addEventHandler(sf::RenderWindow& window, sf::Event event){
    if(MouseEvents<TextInputBox>::mouseClicked(textBox, window)){
        if(typing.isHidden())
            typing.toggleHidden();
        
    }else if(MouseEvents<TextInputBox>::mouseClicked(window, event) && !MouseEvents<TextInputBox>::hovered(textBox, window)){
        
        if(!typing.isHidden())
            typing.toggleHidden();
        
    }
    
    typing.addEventHandler(window, event);
}

void TextInput::update(){
    typing.update();
}


