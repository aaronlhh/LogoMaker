//
//  DropdownMenu.cpp
//  dropdown_menu
//
//  Created by Aaron Lin on 4/28/21.
//

#include "DropDownMenu.hpp"

DropDownMenu::DropDownMenu(){
    box.setText("");
    appear = false;
}

DropDownMenu::DropDownMenu(string word){
    box.setText(word);
    menu.add(word);
    setPosition(0, 0);
    appear = false;
}


DropDownMenu::DropDownMenu(vector<string> vec){
    x = 0;
    y = 0;
    box.setPosition(x, y);
    box.setText(vec.at(0));
    menu.setPosition(0, box.getGlobalBounds().height + 5);
    for(int i = 0; i < vec.size(); i++){
        menu.add(vec.at(i));
    }
    appear = false;
}

void DropDownMenu::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(box);
    if(appear)
        window.draw(menu);
}


void DropDownMenu::addEventHandler(sf::RenderWindow& window, sf::Event event){
    
    if(MouseEvents<InputBox>::mouseClicked(box, window)){
        if(appear){
            appear = false;
        }else{
            appear = true;
        }
    }else if(MouseEvents<ItemList>::mouseClicked(window, event) &&
             !MouseEvents<ItemList>::hovered(menu, window)){
        appear = false;
    }
    
    if(appear){
        menu.addEventHandler(window, event);
    }
}


void DropDownMenu::update(){
    if(menu.isClicked()){
        menu.toggleClick();
        appear = false;
        box.setText(menu.getClicked());
        setPosition(x, y);
    }
    
    if(appear){
        box.setFillColor(sf::Color::Blue);
    }else{
        box.setFillColor(sf::Color::Transparent);
    }
}



void DropDownMenu::resize(float x, float y){
    box.setSize(x, y);
    menu.setSize(x, y);
    setPosition(box.getPosition().x, box.getPosition().y);
}


void DropDownMenu::setPosition(float x, float y){
    this->x = x;
    this->y = y;
    box.setPosition(x, y);
    menu.setPosition(x, y + box.getGlobalBounds().height);
}


void DropDownMenu::add(string item){
    if(box.getText() == ""){
        box.setText(item);
    }
    menu.add(item);
    setPosition(box.getPosition().x, box.getPosition().y);
}


sf::Vector2f DropDownMenu::getPosition(){
    sf::Vector2f vec;
    vec.x = this->x;
    vec.y = this->y;
    return vec;
}

string DropDownMenu::getText(){
    return box.getText();
}

sf::FloatRect DropDownMenu::getGlobalBounds(){
    sf::Vector2f vec = getPosition();
    sf::FloatRect rec;
    rec.top = vec.y;
    rec.left = vec.x;
    rec.width = box.getGlobalBounds().width;
    rec.height = box.getGlobalBounds().height;
    return rec;
}
