//
//  DropdownMenu.hpp
//  dropdown_menu
//
//  Created by Aaron Lin on 4/28/21.
//

#ifndef DropdownMenu_hpp
#define DropdownMenu_hpp

#include "ItemList.hpp"
#include "InputBox.hpp"
#include "GUIComponent.hpp"


class DropDownMenu: public sf::Drawable, public sf::Transformable{
public:
    
    DropDownMenu();
    DropDownMenu(string word);
    DropDownMenu(vector<string> vec);  // given list of string
    
    // setter
    void resize(float x, float y);
    void setPosition(float x, float y);
    void setText(string text);
    
    void add(string item);
    void reset(vector<string> vec);
    
    // accessors
    sf::Vector2f getPosition();
    sf::FloatRect getGlobalBounds();
    string getText();
    
    // GUI
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    
    
    
private:
    InputBox box;
    ItemList menu;
    float x, y;  // record the position
    bool appear;
    
};

#endif /* DropdownMenu_hpp */
