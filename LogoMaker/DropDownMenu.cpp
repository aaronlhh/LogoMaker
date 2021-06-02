//
//  DropdownMenu.cpp
//  dropdown_menu
//
//  Created by Aaron Lin on 4/28/21.
//

#include "DropDownMenu.hpp"


void DropDownMenu::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(box);
    if(States::isStateEnabled(States::APPEAR))
        window.draw(menu);
}


void DropDownMenu::addEventHandler(sf::RenderWindow& window, sf::Event event){
    
    if(MouseEvents<InputBox>::mouseClicked(box, window)){
        if(States::isStateEnabled(States::APPEAR))
            States::setStateEnable(States::APPEAR, false);
        else
            States::setStateEnable(States::APPEAR, true);
    }
    
    if(States::isStateEnabled(States::APPEAR)){
        menu.addEventHandler(window, event);
    }
}


void DropDownMenu::update(){
    if(States::isStateEnabled(States::CLICKED)){
        States::setStateEnable(States::CLICKED, false);
        box.setText(menu.getClicked());
        setPosition(x, y);
    }
}


DropDownMenu::DropDownMenu()
: DropDownMenu(vector<string>{"Arial"}){
    
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
}


void DropDownMenu::resize(float x, float y){
    box.setSize(x, y);
    menu.setSize(x, y);
}


void DropDownMenu::setPosition(float x, float y){
    this->x = x;
    this->y = y;
    box.setPosition(x, y);
    menu.setPosition(x, y + box.getGlobalBounds().height + 5);
}


void DropDownMenu::add(string item){
    menu.add(item);
}


sf::Vector2f DropDownMenu::getPosition(){
    sf::Vector2f vec;
    vec.x = this->x;
    vec.y = this->y;
    return vec;
}

sf::FloatRect DropDownMenu::getGlobalBounds(){
    sf::Vector2f vec = getPosition();
    sf::FloatRect rec;
    rec.top = vec.y;
    rec.left = vec.x;
    rec.width = box.getGlobalBounds().width;
    rec.height = box.getGlobalBounds().height + 5 + menu.getGlobalBounds().height;
    return rec;
}
