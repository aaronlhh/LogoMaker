//
//  ItemList.hpp
//  dropdown_menu
//
//  Created by Aaron Lin on 4/28/21.
//

#ifndef ItemList_hpp
#define ItemList_hpp
#include "Item.hpp"

class ItemList: public sf::Drawable, public sf::Transformable{
public:
    ItemList();
    ItemList(vector<string> vec);   // given a vector of string
    
    // accessors
    sf::FloatRect getGlobalBounds();
    
    void setPosition(float x, float y);
    void setSize(float x, float y);   // x = width of a single Item inside list,
                                      // y = height of a single item
    
    void add(string item);      // add an item to the list
    string getClicked();
    bool isClicked();
    void toggleClick();
    
    // GUI
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    
    
    
private:
    std::vector<Item> itemlist;
    string word;
    bool click;
};


#endif /* ItemList_hpp */
