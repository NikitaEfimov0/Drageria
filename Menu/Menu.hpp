//
// Created by Никита Ефимов on 09.12.2021.
//

#ifndef MVC_MVP_MENU_HPP
#define MVC_MVP_MENU_HPP
#include "SFML/Graphics.hpp"
#include "MenuElement.hpp"
#include "NewGame.hpp"
#include "ReloadGame.hpp"
#include "Exit.hpp"
#include <iostream>
#include <vector>
using namespace sf;
class Menu {
    RenderWindow* window = new RenderWindow(VideoMode(1920, 1080), "MenuFiles");
    std::vector<MenuElement*> menuElems;
    Texture* texture;
    Sprite* sprite;
public:
    Menu(){
        menuElems.push_back(new NewGame());
        menuElems.push_back(new ReloadGame());
        menuElems.push_back(new Exit());
        texture = new Texture();
        texture->loadFromFile("/Users/ddomingo/Desktop/OOP(Univ)/lb_first_sem/src/final.jpg");
        sprite = new Sprite();
        sprite->setTexture(*texture);
        sprite->setTextureRect(IntRect(0, 0, 1920, 1080));
    }

    int checkChose(){
        while(window->isOpen()){
            Event event;
            while(window->pollEvent(event)){
                if(event.type == Event::Closed) {
                    window->close();
                    return 0;
                }
                if(event.type == Event::MouseButtonPressed){
                    if(IntRect(0, 0, 500, 300).contains(Mouse::getPosition(*window)) && Mouse::isButtonPressed(Mouse::Left)){
                        window->close();
                        return 1;
                    }
                }
                if(event.type == Event::MouseButtonPressed){
                    if(IntRect(0, 350, 500, 300).contains(Mouse::getPosition(*window)) && Mouse::isButtonPressed(Mouse::Left)){
                        window->close();
                        return 2;
                    }
                }
                if(event.type == Event::MouseButtonPressed){
                    if(IntRect(0, 700, 500, 300).contains(Mouse::getPosition(*window)) && Mouse::isButtonPressed(Mouse::Left)){
                        window->close();
                        return 0;
                    }
                }
            }
            window->clear();
            window->draw(*sprite);
            for(int i = 0; i < menuElems.size();i++){
                menuElems[i]->draw(*window);
            }
            window->display();
        }
        return 0;
    }

};
#endif //MVC_MVP_MENU_HPP
