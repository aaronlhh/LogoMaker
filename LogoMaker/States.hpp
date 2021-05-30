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
        BACKGROUND_OPACITY, TEXT_X_AXIS, TEXT_Y_AXIS,
        SHADOW_X_AXIS, SHADOW_Y_AXIS};
    
    
    States();
    void operator=(const States& other);
    static bool isStateEnabled(ObjectState state);
    static void setStateEnable(ObjectState state, bool set);
    static sf::Font font;
    static bool loadFont;
    static int TEXT_SIZE;
    static int WINDOW_WIDTH;
    static int WINDOW_HEIGHT;
    
    
private:
    static std::map<ObjectState, bool> states;
    
    
    
};


#endif /* States_hpp */
