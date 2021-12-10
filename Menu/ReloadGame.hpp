//
// Created by Никита Ефимов on 09.12.2021.
//

#ifndef MVC_MVP_RELOADGAME_HPP
#define MVC_MVP_RELOADGAME_HPP
#include "MenuElement.hpp"
class ReloadGame:public MenuElement{
public:
    ReloadGame(){
        texture = new sf::Texture();
        texture->loadFromFile(getPath.find("LoadGame"));
        sprite = new sf::Sprite();
        sprite->setTexture(*texture);
        sprite->setTextureRect(sf::IntRect(0, 0, 500, 150));
        x = 710;
        y = 600;
        sprite->setPosition(x, y);
    }
    void draw(sf::RenderWindow& window){
        window.draw(*sprite);
    }
    void check(){

    }
};
#endif //MVC_MVP_RELOADGAME_HPP
