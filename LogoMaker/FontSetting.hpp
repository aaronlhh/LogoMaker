//
//  FontSetting.hpp
//  LogoMaker
//
//  Created by Aaron Lin on 6/2/21.
//

#ifndef FontSetting_hpp
#define FontSetting_hpp
#include "DropDownMenu.hpp"
#include "GUIComponent.hpp"

class FontSetting: public sf::Drawable, public sf::Transformable{
public:
    FontSetting();
    
    // setup pos
    void setPosition(float x, float y);
    void setFont(States::fonts font, States::fontStyle style);
    
    
    // accessors
    States::fonts getFont();
    States::fontStyle getStyle();
    sf::FloatRect getGlobalBounds();
    sf::Vector2f getPosition();
    
    // GUI
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    
    
private:
    sf::Text label;
    DropDownMenu fontList;
    DropDownMenu styleList;
};

#endif /* FontSetting_hpp */
