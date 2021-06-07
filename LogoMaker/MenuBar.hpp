//
//  MenuBar.hpp
//  DropDownMenuBar
//
//  Created by Aaron Lin on 5/8/21.
//

#ifndef MenuBar_hpp
#define MenuBar_hpp
#include "Menu.hpp"

class MenuBar: public sf::Drawable, public sf::Transformable{
public:
    MenuBar();

    void setPosition(float x, float y);
    void setSize(float x, float y);
    sf::FloatRect getGlobalBounds();

    void draw(sf::RenderTarget& window, sf::RenderStates state) const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();

private:
    vector<Menu> bar;
    int index;
    bool isOpen;
};

#endif /* MenuBar_hpp */
