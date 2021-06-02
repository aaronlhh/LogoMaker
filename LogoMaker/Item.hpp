//
//  Item.hpp
//  dropdown_menu
//
//  Created by Aaron Lin on 4/27/21.
//

#ifndef Item_hpp
#define Item_hpp

#include <iostream>
#include "MouseEvents.hpp"
#include "GUIComponent.hpp"
using namespace std;


class Item: public sf::Drawable, public sf::Transformable{
public:
    Item(string msg, sf::Vector2f vec);
    Item(string msg);
    Item();
    
    // setter
    void setText(string msg);
    void setSize(float x, float y);
    void setPosition(float x, float y);
    void setFillColor(sf::Color color);
    void setFont(sf::Font font);
    
    // globalBound
    sf::FloatRect getGlobalBounds();
    
    // accessors
    string getText() const;
    
    // GUI
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    
    bool operator==(const Item& other);
    
    
    
private:
    sf::Text text;
    sf::RectangleShape box;
    
};

#endif /* Item_hpp */
