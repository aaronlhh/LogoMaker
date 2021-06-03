//
//  ColorList.hpp
//  LogoMaker
//
//  Created by Aaron Lin on 6/1/21.
//

#ifndef ColorList_hpp
#define ColorList_hpp
#include "ColorSquare.hpp"

class ColorList: public sf::Drawable, public sf::Transformable{
public:
    ColorList();
    
    // setup postition make sure they align as a list
    void setPosition(float x, float y);
    
    // return the reference vector of colorsquares
    std::vector<ColorSquare>& getList();
    
    // return the listBox
    sf::FloatRect getGlobalBounds();
    
    // return the corresponding color based on the vector index
    sf::Color& getColorByIndex(int index);
    
    // override
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    
    
private:
    sf::RectangleShape listBox;
    std::vector<ColorSquare> list;
    
};

#endif /* ColorList_hpp */
