//
//  NewFile.hpp
//  LogoMaker
//
//  Created by Aaron Lin on 6/8/21.
//

#ifndef NewFile_hpp
#define NewFile_hpp
#include "TextInput.hpp"
#include "InputBox.hpp"

class NewFile{
public:
    NewFile();
    
    string run();   // return the filename, "NULL" means none
    
private:
    TextInput input;
    InputBox button;
    sf::RenderWindow window;
    sf::Event event;
    string result;
};

#endif /* NewFile_hpp */
