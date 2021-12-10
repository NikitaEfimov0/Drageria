//
// Created by Никита Ефимов on 09.12.2021.
//

#ifndef MVC_MVP_MENUELEMENT_HPP
#define MVC_MVP_MENUELEMENT_HPP
#include "SFML/Graphics.hpp"
#include "../MainFiles/GetPathToTexture.hpp"
class MenuElement{
protected:
    int x, y;
    sf::Texture* texture;
    sf::Sprite* sprite;
    GetPathToTexture getPath;
public:
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual void check() = 0;
};
#endif //MVC_MVP_MENUELEMENT_HPP
