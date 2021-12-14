//
// Created by Никита Ефимов on 13.12.2021.
//

#ifndef MVC_MVP_PAUSEMENU_HPP
#define MVC_MVP_PAUSEMENU_HPP
#include "ResumeGame.hpp"
#include "Exit.hpp"
#include "../Mediator/MedInterface.hpp"
#include "../MainFiles/GetPathToTexture.hpp"
#include "PauseLogo.hpp"
#include "MenuElement.hpp"
using namespace sf;
class PauseMenu{
    GetPathToTexture getPath;
    std::vector<MenuElement*> menuElems;
    RenderWindow* window = new RenderWindow(VideoMode(1920, 1080), "Pause");
    Texture* texture;
    Sprite* sprite;
    MedInterface* mediator;

public:
    PauseMenu(MedInterface* medInterface):mediator(medInterface){
            menuElems.push_back(new Exit());
            menuElems.push_back(new ResumeGame());
            menuElems.push_back(new PauseLogo());
            texture = new Texture();
            texture->loadFromFile(getPath.find("Background"));
            sprite = new Sprite();
            sprite->setTexture(*texture);
            sprite->setTextureRect(IntRect(0, 0, 1920, 1080));
    }
    void pause(){
        while(window->isOpen()){
            Event event;
            while(window->pollEvent(event)){
                if(event.type == Event::Closed) {
                    window->close();
                    mediator->notify(5);
                }
                if(event.type == Event::MouseButtonPressed){
                    if(IntRect(610, 450, 700, 150).contains(Mouse::getPosition(*window)) && Mouse::isButtonPressed(Mouse::Left)){
                        window->close();
                        mediator->notify(2);
                    }
                }
                if(event.type == Event::MouseButtonPressed){
                    if(IntRect(710, 900, 500, 150).contains(Mouse::getPosition(*window)) && Mouse::isButtonPressed(Mouse::Left)){
                        window->close();
                        mediator->notify(5);
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
#endif //MVC_MVP_PAUSEMENU_HPP
