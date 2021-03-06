//
//  BottomMenu.hpp
//  LogoMaker
//
//  Created by Aaron Lin on 5/27/21.
//

#ifndef BottomMenu_hpp
#define BottomMenu_hpp
#include "Slider.hpp"
#include "TextInput.hpp"
#include "ColorBar.hpp"
#include "FontSetting.hpp"
#include "NewFile.hpp"
#include <fstream>

class BottomMenu: public sf::Drawable, public sf::Transformable{
public:
    BottomMenu();
    
    void setPosition(float x, float y);
    
    // accessors
    int getSliderValue(States::sliderType key);
    string getLogoText();
    sf::Color getTextColor();
    sf::Color getBackGroundColor();
    sf::Font& getFont();
    
    // mutators
    void setSliderValue(States::sliderType key, int value);
    void setLogoText(string logo);
    void setTextColor(sf::Color color);
    void setBackGroundColor(sf::Color color);
    void setFont(States::fonts font, States::fontStyle style);
    void reset();       // set values to default
    
    // GUI
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    
    
private:
    std::map<States::sliderType, int> sliderIndex;              // <sliderType, index of slider in vector>
    std::vector<Slider> sliders;
    TextInput inputBox;
    ColorBar bar;
    FontSetting fontList;
    NewFile filePrompt;
};

#endif /* BottomMenu_hpp */
