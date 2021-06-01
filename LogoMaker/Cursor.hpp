//
//  Cursor.hpp
//  text_input
//
//  Created by Aaron Lin on 4/10/21.
//

#ifndef Cursor_hpp
#define Cursor_hpp

#include <SFML/Graphics.hpp>
#include "GUIComponent.hpp"
using namespace std;

class Cursor: public sf::Drawable, public sf::Transformable{
public:
    Cursor();
    Cursor(sf::Vector2f& size);
    
    //from the sf::Drawable class
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    // from EventHandler
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    
    // setter
    void setPosition(float x, float y);
    void setSize(float x, float y);
    
    // accessor
    sf::Vector2f getSize();
    
    
private:
    sf::RectangleShape cursor;
    sf::Clock clock;
    int blinkSpeed = 500;
    bool blinkOn;
    
    void toggleBlinkState();
    
    
};

#endif /* Cursor_hpp */
