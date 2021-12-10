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
#include "Logo.hpp"
#include <iostream>
#include <vector>
#include "../Mediator/MedInterface.hpp"
#include "../MainFiles/GetPathToTexture.hpp"
using namespace sf;
class Menu {
    GetPathToTexture getPath;
    RenderWindow* window = new RenderWindow(VideoMode(1920, 1080), "MenuFiles");
    std::vector<MenuElement*> menuElems;
    Texture* texture;
    Sprite* sprite;
    MedInterface* mediator;

public:
    Menu(MedInterface* medInterface):mediator(medInterface){
        menuElems.push_back(new NewGame());
        menuElems.push_back(new ReloadGame());
        menuElems.push_back(new Exit());
        menuElems.push_back(new Logo());
        texture = new Texture();
        texture->loadFromFile(getPath.find("Background"));
        sprite = new Sprite();
        sprite->setTexture(*texture);
        sprite->setTextureRect(IntRect(0, 0, 1920, 1080));
    }

    void checkChose(){
        while(window->isOpen()){
            Event event;
            while(window->pollEvent(event)){
                if(event.type == Event::Closed) {
                    window->close();
                    mediator->notify(0);
                }
                if(event.type == Event::MouseButtonPressed){
                    if(IntRect(710, 300, 500, 150).contains(Mouse::getPosition(*window)) && Mouse::isButtonPressed(Mouse::Left)){
                        window->close();
                        mediator->notify(1);
                    }
                }
                if(event.type == Event::MouseButtonPressed){
                    if(IntRect(710, 600, 500, 150).contains(Mouse::getPosition(*window)) && Mouse::isButtonPressed(Mouse::Left)){
                        window->close();
                        mediator->notify(2);
                    }
                }
                if(event.type == Event::MouseButtonPressed){
                    if(IntRect(710, 900, 500, 150).contains(Mouse::getPosition(*window)) && Mouse::isButtonPressed(Mouse::Left)){
                        window->close();
                        mediator->notify(0);
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
        return;
    }

};
#endif //MVC_MVP_MENU_HPP
