//
//  Slider.hpp
//  LogoMaker
//
//  Created by Aaron Lin on 5/27/21.
//

#ifndef Slider_hpp
#define Slider_hpp
#include "States.hpp"

class Slider{
public:
    Slider();
    Slider(string label);
    Slider(string label, float length);
    
    // disable copy and assignment operations in case of errors
    Slider(const Slider& other) = delete;
    Slider& operator=(const Slider& other) = delete;
    
    
    
private:
    sf::Text label;
    sf::RectangleShape slider;
    sf::CircleShape knob;
};

#endif /* Slider_hpp */
