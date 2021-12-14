//
// Created by Никита Ефимов on 13.12.2021.
//

#ifndef MVC_MVP_PAUSELOGO_HPP
#define MVC_MVP_PAUSELOGO_HPP
#include "MenuElement.hpp"
class PauseLogo:public MenuElement {
public:
    PauseLogo() {
        texture = new sf::Texture();
        texture->loadFromFile(getPath.find("Pause"));
        sprite = new sf::Sprite();
        sprite->setTexture(*texture);
        sprite->setTextureRect(sf::IntRect(0, 0, 1200, 150));
        x = 360;
        y = 0;
        sprite->setPosition(x, y);
    }

    void draw(sf::RenderWindow &window) {
        window.draw(*sprite);
    }

    void check() {

    }
};
#endif //MVC_MVP_PAUSELOGO_HPP
