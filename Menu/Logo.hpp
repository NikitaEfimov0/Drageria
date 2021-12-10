//
// Created by Никита Ефимов on 10.12.2021.
//

#ifndef MVC_MVP_LOGO_HPP
#define MVC_MVP_LOGO_HPP
#include "MenuElement.hpp"
class Logo:public MenuElement{
public:
    Logo(){
        texture = new sf::Texture();
        texture->loadFromFile(getPath.find("Logo"));
        sprite = new sf::Sprite();
        sprite->setTexture(*texture);
        sprite->setTextureRect(sf::IntRect(0, 0, 1200, 150));
        x = 360;
        y = 0;
        sprite->setPosition(x, y);
    }
    void draw(sf::RenderWindow& window){
        window.draw(*sprite);
    }
    void check(){

    }
};
#endif //MVC_MVP_LOGO_HPP
