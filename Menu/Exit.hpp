//
// Created by Никита Ефимов on 09.12.2021.
//

#ifndef MVC_MVP_EXIT_HPP
#define MVC_MVP_EXIT_HPP
#include "MenuElement.hpp"
class Exit:public MenuElements{
public:
    Exit(){
        texture = new sf::Texture();
        texture->loadFromFile("/Users/ddomingo/Desktop/OOP(Univ)/lb_first_sem/src/Exit.jpg");
        sprite = new sf::Sprite();
        sprite->setTexture(*texture);
        sprite->setTextureRect(sf::IntRect(0, 0, 500, 300));
        x = 0;
        y = 700;
        sprite->setPosition(x, y);
    }
    void draw(sf::RenderWindow& window){
        window.draw(*sprite);
    }
    void check(){

    }
};
#endif //MVC_MVP_EXIT_HPP
