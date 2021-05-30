//
//  BottomMenu.hpp
//  LogoMaker
//
//  Created by Aaron Lin on 5/27/21.
//

#ifndef BottomMenu_hpp
#define BottomMenu_hpp
#include "Slider.hpp"

class BottomMenu: public sf::Drawable, public sf::Transformable{
public:
    BottomMenu();
    
    void setPosition(float x, float y);
    
    // accessors
    int getSliderValue(States::sliderType key);
    
    // GUI
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    
    
private:
    std::map<States::sliderType, int> sliderIndex;              // <sliderType, index of slider in vector>
    std::vector<Slider> sliders;
};

#endif /* BottomMenu_hpp */
