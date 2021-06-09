//
//  TextInput.hpp
//  text_input
//
//  Created by Aaron Lin on 4/5/21.
//

#ifndef TextInput_hpp
#define TextInput_hpp
#include <SFML/Graphics.hpp>
#include "TextInputBox.hpp"
#include "Typing.hpp"
#include "MouseEvents.hpp"


class TextInput: public sf::Drawable, public sf::Transformable{
public:
    TextInput();
    
    // accessors
    sf::FloatRect getGlobalBounds();
    string getLabel();
    string getString();
    
    // setter
    void setLabel(string word);
    void setLabelSize(int size);
    void setPosition(float x, float y);
    void setLength(float len);
    void setSize(float x, float y);
    void setText(string text);
    
    //from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    // from EventHandler
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();

    
private:
    TextInputBox textBox;
    Typing typing;
    sf::Text label;
};

#endif /* TextInput_hpp */
