//
//  ColorSquare.hpp
//  LogoMaker
//
//  Created by Aaron Lin on 6/1/21.
//

#ifndef ColorSquare_hpp
#define ColorSquare_hpp
#include "GUIComponent.hpp"

class ColorSquare: public sf::RectangleShape{
public:
    ColorSquare(sf::Color color);
    ColorSquare();
    
    // accessors
    sf::Color& getColor();
    
    // setter
    void setColor(sf::Color color);
    
private:
    
};

#endif /* ColorSquare_hpp */
