//
//  States.cpp
//  dropdown_menu
//
//  Created by Aaron Lin on 4/27/21.
//

#include "States.hpp"

std::map<States::ObjectState, bool> States::states;
sf::Font States::font;

bool States::loadFont = false;
int States::TEXT_SIZE = 35;
int States::WINDOW_WIDTH = 1500;
int States::WINDOW_HEIGHT = 1500;

States::States(){
//    for(int i = static_cast<int>(APPEAR); i < static_cast<int>(LASTSTATE); i++){
//        states[static_cast<ObjectState>(i)] = false;
//    }
        
}
bool States::isStateEnabled(ObjectState state){
    return states[state];
}


void States::setStateEnable(ObjectState state, bool set){
    states[state] = set;
}
