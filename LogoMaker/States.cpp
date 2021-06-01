//
//  States.cpp
//  dropdown_menu
//
//  Created by Aaron Lin on 4/27/21.
//

#include "States.hpp"

std::map<States::ObjectState, bool> States::states;
std::map<States::fonts, bool> States::fontsLoaded;
std::map<States::fonts, sf::Font> States::fontList;

int States::TEXT_SIZE = 35;
int States::WINDOW_WIDTH = 1500;
int States::WINDOW_HEIGHT = 1500;

bool States::isStateEnabled(ObjectState state){
    return states[state];
}


void States::setStateEnable(ObjectState state, bool set){
    states[state] = set;
}


bool States::isFontLoaded(fonts font){
    return fontsLoaded[font];
}

void States::setFontLoad(fonts font, bool set){
    fontsLoaded[font] = set;
    if(set){
        sf::Font f;
        switch(font){
            case ARIAL:
                if(!f.loadFromFile("Arial.ttf")){
                    cout << "Cannot load file\n";
                }
                fontList[font] = f;
                break;
            case CHARTER:
                if(!f.loadFromFile("Charter.ttc")){
                    cout << "Cannot load file\n";
                }
                fontList[font] = f;
                break;
            case SIGNPAINTER:
                if(!f.loadFromFile("SignPainter.ttc")){
                    cout << "Cannot load file\n";
                }
                fontList[font] = f;
                break;
            case OPENSANS:
                if(!f.loadFromFile("OpenSans-Bold.ttf")){
                    cout << "Cannot load file\n";
                }
                fontList[font] = f;
                break;
        }
    }
}


sf::Font& States::getFont(fonts font){
    return fontList[font];
}
