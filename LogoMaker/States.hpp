//
//  States.hpp
//  dropdown_menu
//
//  Created by Aaron Lin on 4/27/21.
//

#ifndef States_hpp
#define States_hpp

#include <map>
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class States{
public:
    enum ObjectState{
        APPEAR, CLICKED, LASTSTATE
    };
    
    // BottomMenu sliders enum
    enum sliderType { TEXT_OPACITY, FONT_SIZE, SKEW, SHADOW_OPACITY,
        BACKGROUND_OPACITY,TEXT_ROTATE,SHADOW_ROTATE, TEXT_X_AXIS, TEXT_Y_AXIS,
        SHADOW_X_AXIS, SHADOW_Y_AXIS};
    
    // fonts
    enum fonts {ARIAL, VERDANA, COURIER_NEW, TIME_NEW_ROMAN};
    enum fontStyle {REGULAR, BOLD, ITALICS};
    
    // colors
    enum colors {RED, YELLOW, GREEN, LIGHTBLUE, BLUE, PURPLE, BLACK, WHITE};
    

    // global accessors and mutators
    void operator=(const States& other);
    static bool isStateEnabled(ObjectState state);
    static void setStateEnable(ObjectState state, bool set);
    
    static bool isFontLoaded(fonts font);
    static void setFontLoad(fonts font, bool set);
    static sf::Font& getFont(fonts font, fontStyle style);
    
    static int TEXT_SIZE;
    static int WINDOW_WIDTH;
    static int WINDOW_HEIGHT;
    
    
private:
    static std::map<ObjectState, bool> states;
    static std::map<fonts, bool> fontsLoaded;
    static std::map<fonts, std::vector<sf::Font>> fontList;
    
};


#endif /* States_hpp */
