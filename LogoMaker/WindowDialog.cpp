//
//  WindowDialog.cpp
//  LogoMaker
//
//  Created by Aaron Lin on 6/7/21.
//

#include "WindowDialog.hpp"

WindowDialog::WindowDialog(){
    
}


void WindowDialog::run(){
    window.create(sf::VideoMode({1000,1000}), "WindowDialog");
    FileTree tree;
    string path = "projs";
    tree.push("projs");
    for(auto& p : fs::directory_iterator(path)){
        tree.push(p.path().filename().string());
    }
    while(window.isOpen()){
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
            tree.addEventHandler(window, event);
            if(States::isStatusSet(States::OPEN_PROJ)){
                window.close();  // goes back to bottomMenu
            }
        }
        tree.update();
        window.clear();
        window.draw(tree);
        window.display();
    }
}
