//
//  ColorBar.hpp
//  LogoMaker
//
//  Created by Aaron Lin on 6/2/21.
//

#ifndef ColorBar_hpp
#define ColorBar_hpp
#include "ColorPicker.hpp"

class ColorBar: public sf::Drawable, public sf::Transformable{
public:
    
    // align two labels and two color pickers in a horizontal line
    ColorBar();
    
    // setPosition()
    void setPosition(float x, float y);
    
    // globalbound
    sf::FloatRect getGlobalBounds();
    
    // accessors
    sf::Color& getTextColor();
    sf::Color& getBackGroundColor();
    
    // override
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    
private:
    ColorPicker textColor;
    sf::Text textLabel;
    ColorPicker backgroundColor;
    sf::Text backgroundLabel;
};

#endif /* ColorBar_hpp */
