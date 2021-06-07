//
//  Menu.hpp
//  DropDownMenuBar
//
//  Created by Aaron Lin on 5/8/21.
//

#ifndef Menu_hpp
#define Menu_hpp
#include "ItemList.hpp"


class Menu: public sf::Drawable, public sf::Transformable{
public:
    Menu();
    
    void setPosition(float x, float y);
    void setSize(float x, float y);
    sf::FloatRect getGlobalBounds();
    void setString(string title);
    void add(string word);
    bool isHidden();
    void setHidden(bool h);
    bool titleHovered(sf::RenderWindow& window);
    bool titleClicked(sf::RenderWindow& window);
    bool isClicked();
    string getClicked();
    
    void draw(sf::RenderTarget& window, sf::RenderStates state) const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    
    
private:
    Item title;
    ItemList list;
    string word;
    bool appear;
    bool clicked;
};

#endif /* Menu_hpp */
