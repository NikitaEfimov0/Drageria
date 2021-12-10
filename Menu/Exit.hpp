//
// Created by Никита Ефимов on 09.12.2021.
//

#ifndef MVC_MVP_EXIT_HPP
#define MVC_MVP_EXIT_HPP
#include "MenuElement.hpp"
class Exit:public MenuElement{
public:
    Exit(){
        texture = new sf::Texture();
        texture->loadFromFile(getPath.find("Exit"));
        sprite = new sf::Sprite();
        sprite->setTexture(*texture);
        sprite->setTextureRect(sf::IntRect(0, 0, 500, 150));
        x = 710;
        y = 900;
        sprite->setPosition(x, y);
    }
    void draw(sf::RenderWindow& window){
        window.draw(*sprite);
    }
    void check(){

    }
};
#endif //MVC_MVP_EXIT_HPP
