//
// Created by Никита Ефимов on 13.12.2021.
//

#ifndef MVC_MVP_RESUMEGAME_HPP
#define MVC_MVP_RESUMEGAME_HPP
#include "MenuElement.hpp"
class ResumeGame:public MenuElement{
public:
    ResumeGame(){
        texture = new sf::Texture();
        texture->loadFromFile(getPath.find("ResumeGame"));
        sprite = new sf::Sprite();
        sprite->setTexture(*texture);
        sprite->setTextureRect(sf::IntRect(0, 0, 700, 150));
        x = 610;
        y = 450;
        sprite->setPosition(x, y);
    }
    void draw(sf::RenderWindow& window){
        window.draw(*sprite);
    }
    void check(){

    }
};
#endif //MVC_MVP_RESUMEGAME_HPP
