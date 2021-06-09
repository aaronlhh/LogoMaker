//
//  Typing.hpp
//  text_input
//
//  Created by Aaron Lin on 4/8/21.
//

#ifndef Typing_hpp
#define Typing_hpp
#include <iostream>

#include <SFML/Graphics.hpp>
#include "GUIComponent.hpp"
#include "Cursor.hpp"
#include "TextInputBox.hpp"



using namespace std;

class Typing: public sf::Drawable, public sf::Transformable{
public:
    Typing();
    
    // setter
    void setPosition(float x, float y);
    void toggleHidden();
    void setSize(float size);   // character size
    void setText(string text);
    
    // accessor
    string getString();
    bool isHidden();
    sf::FloatRect getGlobalBounds();

    // GUI
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void update();


private:
    Cursor cursor;
    sf::Text text;
    bool hidden;        // if hidden, dont draw cursor
};

#endif /* Typing_hpp */
