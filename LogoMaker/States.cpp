//
//  States.cpp
//  dropdown_menu
//
//  Created by Aaron Lin on 4/27/21.
//

#include "States.hpp"

std::map<States::ObjectState, bool> States::states;
std::map<States::fonts, bool> States::fontsLoaded;
std::map<States::fonts, std::vector<sf::Font>> States::fontList;

int States::TEXT_SIZE = 35;
int States::WINDOW_WIDTH = 1500;
int States::WINDOW_HEIGHT = 1400;

std::map<States::Image, bool> States::loadImage;
sf::Texture States::fileTexture;
sf::Texture States::DirTexture;
string States::fileToOpen;
std::map<States::MenuBar, bool> States::status;

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
        sf::Font f1;
        sf::Font f2;
        sf::Font f3;
        switch(font){
            case ARIAL:
                if(!f1.loadFromFile("Arial.ttf")){
                    cout << "Cannot load file\n";
                }
                if(!f2.loadFromFile("Arial Italic.ttf")){
                    cout << "Cannot load file\n";
                }
                if(!f3.loadFromFile("Arial Bold.ttf")){
                    cout << "Cannot load file\n";
                }
                fontList[font].push_back(f1);
                fontList[font].push_back(f2);
                fontList[font].push_back(f3);
                break;
            case COURIER_NEW:
                if(!f1.loadFromFile("Courier New.ttf")){
                    cout << "Cannot load file\n";
                }
                if(!f2.loadFromFile("Courier New Italic.ttf")){
                    cout << "Cannot load file\n";
                }
                if(!f3.loadFromFile("Courier New Bold.ttf")){
                    cout << "Cannot load file\n";
                }
                fontList[font].push_back(f1);
                fontList[font].push_back(f2);
                fontList[font].push_back(f3);
                break;
            case VERDANA:
                if(!f1.loadFromFile("Verdana.ttf")){
                    cout << "Cannot load file\n";
                }
                if(!f2.loadFromFile("Verdana Italic.ttf")){
                    cout << "Cannot load file\n";
                }
                if(!f3.loadFromFile("Verdana Bold.ttf")){
                    cout << "Cannot load file\n";
                }
                fontList[font].push_back(f1);
                fontList[font].push_back(f2);
                fontList[font].push_back(f3);
                break;
            case TIME_NEW_ROMAN:
                if(!f1.loadFromFile("Times New Roman.ttf")){
                    cout << "Cannot load file\n";
                }
                if(!f2.loadFromFile("Times New Roman Italic.ttf")){
                    cout << "Cannot load file\n";
                }
                if(!f3.loadFromFile("Times New Roman Bold.ttf")){
                    cout << "Cannot load file\n";
                }
                fontList[font].push_back(f1);
                fontList[font].push_back(f2);
                fontList[font].push_back(f3);
                break;
        }
    }
}


sf::Font& States::getFont(fonts font, fontStyle style){
    switch(font){
        case ARIAL:
            if(style == REGULAR){
                return fontList[font].at(0);
            }else if(style == ITALICS){
                return fontList[font].at(1);
            }else{
                return fontList[font].at(2);
            }
        case VERDANA:
            if(style == REGULAR){
                return fontList[font].at(0);
            }else if(style == ITALICS){
                return fontList[font].at(1);
            }else{
                return fontList[font].at(2);
            }
        case COURIER_NEW:
            if(style == REGULAR){
                return fontList[font].at(0);
            }else if(style == ITALICS){
                return fontList[font].at(1);
            }else{
                return fontList[font].at(2);
            }
        case TIME_NEW_ROMAN:
            if(style == REGULAR){
                return fontList[font].at(0);
            }else if(style == ITALICS){
                return fontList[font].at(1);
            }else{
                return fontList[font].at(2);
            }
    }
}


bool States::isStatusSet(MenuBar key){
    return status[key];
}


void States::setStatus(MenuBar key, bool set){
    status[key] = set;
}
