//
//  ColorGradient.cpp
//  LogoMaker
//
//  Created by Aaron Lin on 6/1/21.
//

#include "ColorGradient.hpp"


ColorGradient::ColorGradient(sf::Color color){
    gradients.setPrimitiveType(sf::Points);
    int height = 256;
    int width = 256;
    gradients.resize(height*width);      // color range 0-255
    background.setSize({256, 256});
    background.setFillColor(sf::Color::Black);
    setColor(color);
}

ColorGradient::ColorGradient()
: ColorGradient(sf::Color::Blue){
    
}


void ColorGradient::setPosition(float x, float y){
    int height = gradients.getBounds().height+1;
    int width = gradients.getBounds().width+1;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            sf::Vertex& vertex = gradients[i*width + j];
            vertex.position = sf::Vector2f(x+j,y+i);
        }
    }
    background.setPosition(x, y);
}


sf::FloatRect ColorGradient::getGlobalBounds(){
    return gradients.getBounds();
}



sf::Color ColorGradient::getColor(sf::Vector2i pos){
    int height = gradients.getBounds().height;
    int width = gradients.getBounds().width;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            sf::Vertex& vertex = gradients[i*width + j];
            if((int)vertex.position.x == pos.x && (int)vertex.position.y == pos.y){
                return vertex.color;
            }
        }
    }
    return none;
}


void ColorGradient::setColor(sf::Color color){
    int height = 256;
    int width = 256;
    int r = color.r, g = color.g, b = color.b;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            sf::Vertex& vertex = gradients[i*width + j];

            // set color
            // r,g,b are either 0 or 255
            // from up to down, a increases from 0 to 255
            // from left to right, from white to real color
            int newR = (r == 255)? 255:(255-j);
            int newG = (g == 255)? 255:(255-j);
            int newB = (b == 255)? 255:(255-j);
            int newA = i;
            vertex.color = sf::Color(newR, newG, newB, newA);
            vertex.position = sf::Vector2f(j,i);
        }
    }
}


void ColorGradient::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(background);
    window.draw(gradients);
}
