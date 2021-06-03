//
//  ItemList.cpp
//  dropdown_menu
//
//  Created by Aaron Lin on 4/28/21.
//

#include "ItemList.hpp"

ItemList::ItemList(){

}


ItemList::ItemList(vector<string> vec){
    for(int i = 0; i < vec.size(); ++i){
        add(vec.at(i));
    }
    word = "";
}

void ItemList::setPosition(float x, float y){
    int index = 0;
    for(int i = 0; i < itemlist.size(); i++){
        itemlist.at(i).setPosition(x, y + index * itemlist.at(i).getGlobalBounds().height);
        ++index;
    }
}


void ItemList::setSize(float x, float y){
    for(int i = 0; i < itemlist.size(); i++){
        itemlist.at(i).setSize(x, y);
    }
    
    setPosition(getPosition().x, getPosition().y);
    
}


void ItemList::add(string item){
    if(itemlist.empty()){
        Item temp(item);
        itemlist.push_back(temp);
        setPosition(getPosition().x, getPosition().y);
        return;
    }
    
    sf::FloatRect dimension = itemlist.at(0).getGlobalBounds();
    Item temp(item);
    temp.setSize(dimension.width, dimension.height);
    itemlist.push_back(temp);
    setPosition(getPosition().x, getPosition().y);
}


sf::FloatRect ItemList::getGlobalBounds(){
    sf::FloatRect rec = itemlist.at(0).getGlobalBounds();
    int count = (int)itemlist.size();
    rec.height *= count;
    return rec;
}

string ItemList::getClicked(){
    return word;
}

bool ItemList::isClicked(){
    return click;
}

void ItemList::toggleClick(){
    click = false;
}


void ItemList::addEventHandler(sf::RenderWindow& window, sf::Event event){
    for(int i = 0; i < itemlist.size(); i++){
        if(MouseEvents<Item>::hovered(itemlist.at(i), window)){
            itemlist.at(i).setFillColor(sf::Color::Blue);
        }else{
            itemlist.at(i).setFillColor(sf::Color::Black);
        }
        
        if(MouseEvents<Item>::mouseClicked(itemlist.at(i), window)){
            // if mouse clicked on an option, closed the bar
            // set clicked state to be true
            click = true;
            word = itemlist.at(i).getText();
        }
    }
}

void ItemList::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    if(itemlist.empty())
        return;
    for(int i = 0; i < itemlist.size(); i++){
        window.draw(itemlist.at(i));
    }
}


