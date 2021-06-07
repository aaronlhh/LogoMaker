//
//  MenuBar.cpp
//  DropDownMenuBar
//
//  Created by Aaron Lin on 5/8/21.
//

#include "MenuBar.hpp"


MenuBar::MenuBar(){
    Menu temp;
    temp.add("File");
    temp.add("Open Project");
    temp.add("Close Project");
    temp.add("New Project");
    temp.add("Save Project");
    temp.add("Quit");
    bar.push_back(temp);
    
    Menu temp2;
    temp2.add("Edit");
    temp2.add("Redo");
    temp2.add("Undo");
    bar.push_back(temp2);
    
    Menu temp3;
    temp3.add("Render");
    temp3.add("Export Image");
    bar.push_back(temp3);
    setPosition(0,0);
    
    isOpen = false;
    index = -1;
}


void MenuBar::setPosition(float x, float y){
    int index = 0;
    for(vector<Menu>::iterator i = bar.begin(); i < bar.end(); ++i){
        i->setPosition(x + index*i->getGlobalBounds().width, y);
        index++;
    }
}


void MenuBar::setSize(float x, float y){
    for(vector<Menu>::iterator i = bar.begin(); i < bar.end(); ++i){
        i->setSize(x, y);
    }
    setPosition(bar.begin()->getGlobalBounds().left, bar.begin()->getGlobalBounds().top);
}


sf::FloatRect MenuBar::getGlobalBounds(){
    sf::FloatRect rect;
    rect = bar.begin()->getGlobalBounds();
    rect.width *= bar.size();
    return rect;
}



void MenuBar::draw(sf::RenderTarget& window, sf::RenderStates state) const{
    for(Menu m: bar){
        window.draw(m);
    }
}


void MenuBar::addEventHandler(sf::RenderWindow& window, sf::Event event){
    
    for(vector<Menu>::iterator i = bar.begin(); i < bar.end(); ++i){
        i->addEventHandler(window, event);
    }
    
    bool temp = false;
    for(int k = 0; k < bar.size(); ++k){
        if(!bar.at(k).isHidden()){
            temp = true;
            index = k;
            break;
        }
    }
    isOpen = temp;
    if(!isOpen)
        index = -1;
    
    
    
    for(int j = 0; j < bar.size(); ++j){
        if(bar.at(j).titleHovered(window) && isOpen && j != index){
            bar.at(j).setHidden(false);
            bar.at(index).setHidden(true);
            index = j;
        }
    }
    setPosition(bar.at(0).getPosition().x, bar.at(0).getPosition().y);

}


void MenuBar::update(){
    for(vector<Menu>::iterator i = bar.begin(); i < bar.end(); ++i){
        i->update();
        if(i->isClicked()){
            string word = i->getClicked();
            if(word == "Open Project"){
                cout << "Open proj\n";
            }else if(word == "Close Project"){
                cout << "Close Project\n";
            }else if(word == "New Project"){
                cout << "New Project\n";
            }else if(word == "Save Project"){
                cout << "Save Project\n";
            }else if(word == "Quit"){
                cout << "Quit\n";
            }else if(word == "Redo"){
                cout << "Redo\n";
            }else if(word == "Undo"){
                cout << "Undo\n";
            }else if(word == "Export Image"){
                cout << "export\n";
            }
        }
    }
}
