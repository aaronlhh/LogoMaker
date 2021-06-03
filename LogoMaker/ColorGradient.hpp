//
//  ColorGradient.hpp
//  LogoMaker
//
//  Created by Aaron Lin on 6/1/21.
//

#ifndef ColorGradient_hpp
#define ColorGradient_hpp
#include "GUIComponent.hpp"

class ColorGradient: public sf::Drawable, public sf::Transformable{
public:
    ColorGradient(sf::Color color);
    ColorGradient();
    
    // adjust positions
    void setPosition(float x, float y);
    
    // globalBounds of the entire box
    sf::FloatRect getGlobalBounds();
    
    // getColor from the corresponding position/point
    sf::Color getColor(sf::Vector2i pos);
    
    // setup color of the gradient
    void setColor(sf::Color color);
    
    // override
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    
private:
    sf::VertexArray gradients;  // array of points with diff. colors
    sf::RectangleShape background;
    sf::Color none;
};

#endif /* ColorGradient_hpp */
