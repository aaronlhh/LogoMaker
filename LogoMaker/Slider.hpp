//
//  Slider.hpp
//  LogoMaker
//
//  Created by Aaron Lin on 5/27/21.
//

#ifndef Slider_hpp
#define Slider_hpp
#include "GUIComponent.hpp"

class Slider: public sf::Drawable, public sf::Transformable{
public:
    // constructors
    Slider();
    Slider(string label);
    Slider(string label, float length, float defaultVal = 0);
    
    // modification for slider
    void setPosition(float x, float y);         // set position of slider
    void setMax(float max);                 // set max number of slider
    void setLabel(string label);            // set label of slider
    
    // accessors
    int getCurVal();
    string getLabel();
    sf::FloatRect getGlobalBounds();
    sf::Vector2f getPosition();

    // GUI
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    
    
private:
    sf::Text label;                 // label of slider
    sf::Text curVal;                // current value of slider
    sf::RectangleShape slider;
    sf::CircleShape knob;
    int relPos;                // relative position of knob in ref. of slider's starting pt
    
    void setupPosition();           // adjust position of curVal, slider and knob
};

#endif /* Slider_hpp */
