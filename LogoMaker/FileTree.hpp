//
//  FileTree.hpp
//  FIleTree
//
//  Created by Aaron Lin on 5/16/21.
//

#ifndef FileTree_hpp
#define FileTree_hpp
#include "FileNode.hpp"

class FileTree: public sf::Drawable, public sf::Transformable{
private:
    //the root node of the tree
    FileNode* root = nullptr;
    
    //finds the parent and add the item to the parent.
    // If the parent isn't found, a new parent is created
    void push(FileNode*& root, std::string parent, std::string item);

    
    sf::Vector2f initPosition = {0, 0};
    
public:
    //constructors
    FileTree();
    
    //this is the public version of push
    void push(std::string parent, std::string item = "NULL");
    
    //draws the root node of the tree
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    
    //calls the traverse function to add the event handlers to each node
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    
    //does nothing now
    virtual void update();

    //does nothing now
    virtual sf::FloatRect getGlobalBounds();
};

#endif /* FileTree_hpp */
