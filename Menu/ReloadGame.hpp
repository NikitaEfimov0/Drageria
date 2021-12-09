//
// Created by Никита Ефимов on 09.12.2021.
//

#ifndef MVC_MVP_RELOADGAME_HPP
#define MVC_MVP_RELOADGAME_HPP
#include "MenuElement.hpp"
class ReloadGame:public MenuElements{
public:
    ReloadGame(){
        texture = new sf::Texture();
        texture->loadFromFile("/Users/ddomingo/Desktop/OOP(Univ)/lb_first_sem/src/loadGame.jpg");
        sprite = new sf::Sprite();
        sprite->setTexture(*texture);
        sprite->setTextureRect(sf::IntRect(0, 0, 500, 300));
        x = 0;
        y = 350;
        sprite->setPosition(x, y);
    }
    void draw(sf::RenderWindow& window){
        window.draw(*sprite);
    }
    void check(){

    }
};
#endif //MVC_MVP_RELOADGAME_HPP
