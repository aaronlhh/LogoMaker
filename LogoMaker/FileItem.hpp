//
//  FileItem.hpp
//  FIleTree
//
//  Created by Aaron Lin on 5/15/21.
//

#ifndef FileItem_hpp
#define FileItem_hpp
#include "GUIComponent.hpp"
#include "MouseEvents.hpp"
#include <iostream>

class FileItem: public sf::Transformable, public sf::Drawable{
public:
    //Constructors
    FileItem();
    FileItem(States::Image icon, std::string text, sf::Vector2f size = {500,100}, sf::Vector2f position = {0,0});
    
    //GUIComponent pure virtual functions, refer to the TextInput Project for Info
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    //I use this function to highlight the item when clicked, and unhighlight when something
    //else is clicked
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    //Returns the bounds of the item
    sf::FloatRect getGlobalBounds() const;
    //returns the size of the item
    sf::Vector2f getSize() const;
    //returns the size of the item
    sf::Vector2f getPosition() const;
    //sets the position of the item
    void setPosition(sf::Vector2f pos);
    //uses an enum to change the icon to a folder or file
    void setIcon(States::Image icon);
    //if color is blue, that means clicked. if transparent then not clicked
    sf::Color getFillColor() const;
    // set name of fileNode
    void setName(string name);
    // accessors
    States::Image getIcon();
    string getName();
    
    
private:
    //this is the folder or file icon
    sf::Sprite icon;
    sf::Text text;
    sf::RectangleShape box;
    float padding = 20;
};

#endif /* FileItem_hpp */
