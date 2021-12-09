//
// Created by Никита Ефимов on 22.11.2021.
//

#ifndef MVC_MVP_FINISH_HPP
#define MVC_MVP_FINISH_HPP
#include "SFML/Graphics.hpp"
#include <iostream>
#include "GetPathToTexture.hpp"
class Finish{
    GetPathToTexture set_path;
    GetPathToTexture set_path_2;
    sf::Texture* imageW;
    sf::Sprite* spriteW;
    sf::Texture* imageL;
    sf::Sprite* spriteL;

public:
    Finish(){
        imageW = new sf::Texture();
        imageW->loadFromFile(set_path.find("Finish"));
        spriteW = new sf::Sprite();
        spriteW->setTexture(*imageW);
        spriteW->setTextureRect(sf::IntRect(0, 0, 1920, 1000));
        spriteW->setOrigin(1920.0/2, 1000.0/2);

        imageL = new sf::Texture();
        imageL->loadFromFile(set_path_2.find("Lose"));
        spriteL = new sf::Sprite();
        spriteL->setTexture(*imageL);
        spriteL->setTextureRect(sf::IntRect(0, 0, 1920, 1000));
        spriteL->setOrigin(1920.0/2, 1000.0/2);
    }
    sf::Sprite* returnImageW(){return spriteW;}
    sf::Sprite* returnImageL(){return spriteL;}
};
#endif //MVC_MVP_FINISH_HPP
