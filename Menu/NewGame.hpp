//
// Created by Никита Ефимов on 09.12.2021.
//

#ifndef MVC_MVP_NEWGAME_HPP
#define MVC_MVP_NEWGAME_HPP
#include "SFML/Graphics.hpp"
#include "MenuElement.hpp"
class NewGame:public MenuElement{
public:
    NewGame(){
        texture = new sf::Texture();
        texture->loadFromFile(getPath.find("NewGame"));
        sprite = new sf::Sprite();
        sprite->setTexture(*texture);
        sprite->setTextureRect(sf::IntRect(0, 0, 500, 150));
        x = 710;
        y = 300;
        sprite->setPosition(x, y);
    }
    void draw(sf::RenderWindow& window){
        window.draw(*sprite);
    }
    void check(){

    }
};
#endif //MVC_MVP_NEWGAME_HPP
