//
//  TextInputBox.hpp
//  text_input
//
//  Created by Aaron Lin on 4/7/21.
//

#ifndef TextInputBox_hpp
#define TextInputBox_hpp
#include <SFML/Graphics.hpp>
#include "MouseEvents.hpp"


class TextInputBox: public sf::RectangleShape{
public:
    TextInputBox();
    TextInputBox(const sf::Vector2f& size);
    TextInputBox(sf::Color color);
    TextInputBox(float width, float height, sf::Color color);
    
private:
    
    
};

#endif /* TextInputBox_hpp */
