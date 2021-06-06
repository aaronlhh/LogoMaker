//
//  InputBox.hpp
//  dropdown_menu
//
//  Created by Aaron Lin on 4/27/21.
//

#ifndef InputBox_hpp
#define InputBox_hpp

#include <iostream>
#include <SFML/Graphics.hpp>
#include "GUIComponent.hpp"
using namespace std;

class InputBox: public sf::Drawable, public sf::Transformable{
public:
    InputBox(string msg, sf::Vector2f vec, sf::Color color);
    InputBox(string msg, sf::Vector2f vec);
    InputBox(string msg);
    InputBox();
    
    // setter
    void setText(string msg);
    void setSize(float x, float y);
    void setPosition(float x, float y);
    sf::FloatRect getGlobalBounds();
    void setFillColor(sf::Color color);
    
    // accessors
    string getText();
    
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    
private:
    sf::RectangleShape box;
    sf::Text text;
};

#endif /* InputBox_hpp */
