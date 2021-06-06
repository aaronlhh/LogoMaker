//
//  LogoMaker.hpp
//  LogoMaker
//
//  Created by Aaron Lin on 5/30/21.
//

#ifndef LogoMaker_hpp
#define LogoMaker_hpp
#include "BottomMenu.hpp"
#include "MenuBar.hpp"

class LogoMaker: public sf::Drawable, public sf::Transformable{
public:
    LogoMaker();
    
    // setter
    void setPosition(float x, float y);
    
    // accessors
    sf::Vector2f getPosition();
    sf::FloatRect getGlobalBounds();
    
    // GUI
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    
    
private:
    BottomMenu menu;
//    MenuBar bar;
    sf::Text text;
    sf::Text shadow;
    sf::RectangleShape background;
    
};

#endif /* LogoMaker_hpp */
