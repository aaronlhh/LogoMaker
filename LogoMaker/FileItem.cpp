//
//  FileItem.cpp
//  FIleTree
//
//  Created by Aaron Lin on 5/15/21.
//

#include "FileItem.hpp"



FileItem::FileItem()
: FileItem(States::FILE_ICON, "File 1", {500,100}, {0,0}){
    
}


FileItem::FileItem(States::Image icon, std::string text, sf::Vector2f size, sf::Vector2f position){
    // loading textures
    if(!States::loadImage[icon]){
        if(icon == States::FILE_ICON)
            States::fileTexture.loadFromFile("file.png");
        else if(icon == States::DIRECTORY_ICON)
            States::DirTexture.loadFromFile("folder.png");
        States::loadImage[icon] = true;
    }
    if(!States::isFontLoaded(States::ARIAL)){
        States::setFontLoad(States::ARIAL, true);
    }
    
    // set outer box
    box.setSize(size);
    box.setFillColor(sf::Color::Transparent);
    
    
    // set icon
    if(icon == States::FILE_ICON)
        this->icon.setTexture(States::fileTexture);
    else if(icon == States::DIRECTORY_ICON)
        this->icon.setTexture(States::DirTexture);
//    int length = this->icon.getGlobalBounds().width + padding;
    
    
    // set text
    this->text.setFont(States::getFont(States::ARIAL, States::REGULAR));
    this->text.setString(text);
    this->text.setFillColor(sf::Color::White);
    this->text.setCharacterSize(size.y/2);
//    length += this->text.getGlobalBounds().width;
    
    // set position
    setPosition(position);
}


void FileItem::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(box);
    window.draw(text);
    window.draw(icon);
}


void FileItem::addEventHandler(sf::RenderWindow& window, sf::Event event){
    
    if(MouseEvents<sf::RectangleShape>::mouseClicked(box, window)){
        if(box.getFillColor() == sf::Color::Blue)
            box.setFillColor(sf::Color::Transparent);
        else if(box.getFillColor() == sf::Color::Transparent)
            box.setFillColor(sf::Color::Blue);
        
    }else if(MouseEvents<sf::RectangleShape>::mouseClicked(window, event) &&
             !MouseEvents<sf::RectangleShape>::mouseClicked(box, window)){
        box.setFillColor(sf::Color::Transparent);
    }
    
    if(MouseEvents<sf::RectangleShape>::mouseDoubleClicked()){
        doubleClicked = true;
    }else{
        doubleClicked = false;
    }
}


sf::FloatRect FileItem::getGlobalBounds() const{
    return box.getGlobalBounds();
}


sf::Vector2f FileItem::getSize() const{
    return box.getSize();
}


sf::Vector2f FileItem::getPosition() const{
    return box.getPosition();
}


void FileItem::setPosition(sf::Vector2f pos){
    
    int length = this->icon.getGlobalBounds().width + padding;
    length += this->text.getGlobalBounds().width;
    
    this->box.setPosition(pos);
    
    if(text.getString().find("File") != std::string::npos){
        this->icon.setPosition(box.getPosition().x + box.getGlobalBounds().width/3 - length/2 + 5,
                               box.getPosition().y + box.getGlobalBounds().height/2 - this->icon.getGlobalBounds().height/2);
        
        this->text.setPosition(box.getPosition().x + box.getGlobalBounds().width/3 - length/2 + this->icon.getGlobalBounds().width + padding + 5,
                               box.getPosition().y + box.getGlobalBounds().height/2 - this->text.getGlobalBounds().height/1.5);
        
    }else{
        this->icon.setPosition(box.getPosition().x + box.getGlobalBounds().width/2 - length/2,
                               box.getPosition().y + box.getGlobalBounds().height/2 - this->icon.getGlobalBounds().height/2);
        
        this->text.setPosition(box.getPosition().x + box.getGlobalBounds().width/2 - length/2 + this->icon.getGlobalBounds().width + padding,
                               box.getPosition().y + box.getGlobalBounds().height/2 - this->text.getGlobalBounds().height/1.5);
    }
}


void FileItem::setIcon(States::Image icon){
    if(!States::loadImage[icon]){
        if(icon == States::FILE_ICON)
            States::fileTexture.loadFromFile("file.png");
        else if(icon == States::DIRECTORY_ICON)
            States::DirTexture.loadFromFile("folder.png");
        States::loadImage[icon] = true;
    }else{
        if(icon == States::FILE_ICON)
            this->icon.setTexture(States::fileTexture);
        else if(icon == States::DIRECTORY_ICON)
            this->icon.setTexture(States::DirTexture);
    }
}

sf::Color FileItem::getFillColor() const{
    return box.getFillColor();
}


void FileItem::setName(string name){
    text.setString(name);
}
