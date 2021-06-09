//
//  WindowDialog.hpp
//  LogoMaker
//
//  Created by Aaron Lin on 6/7/21.
//

#ifndef WindowDialog_hpp
#define WindowDialog_hpp
#include "GUIComponent.hpp"
#include "FileTree.hpp"
#include <filesystem>
namespace fs = std::__fs::filesystem;

class WindowDialog{
public:
    WindowDialog();
    void run();
    
private:
    sf::RenderWindow window;
    sf::Event event;
    
};

#endif /* WindowDialog_hpp */
