//
// Created by Никита Ефимов on 02.12.2021.
//

#ifndef MVC_MVP_KEYREADERFORWINDOW_HPP
#define MVC_MVP_KEYREADERFORWINDOW_HPP
#include "SFML/Graphics.hpp"
#include "KeysForWindow.hpp"
class KeyReaderForWindow{
    KeysForWindow<sf::Keyboard::Escape> keys;
public:
    bool checkExit(){
        if(sf::Keyboard::isKeyPressed(keys.returnExit()))
            return true;
        return false;
    }
};
#endif //MVC_MVP_KEYREADERFORWINDOW_HPP
