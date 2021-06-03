//
//  ColorPicker.hpp
//  LogoMaker
//
//  Created by Aaron Lin on 6/1/21.
//

#ifndef ColorPicker_hpp
#define ColorPicker_hpp
#include "ColorGradient.hpp"
#include "ColorList.hpp"

class ColorPicker: public sf::Drawable, public sf::Transformable{
public:
    ColorPicker();
    
    // return globalBounds (globalBounds of single colorSquare
    sf::FloatRect getGlobalBounds();
    
    // setup position
    void setPosition(float x, float y);
    
    // get color that the user currently picked
    sf::Color& getColor();
    void setColor(sf::Color color);
    
    // GUI parts
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void update();
    
private:
    ColorList list;
    ColorGradient gradient;
    ColorSquare square;
    sf::Color colorGot;
    bool showGradient;
    bool showList;
};



#endif /* ColorPicker_hpp */
