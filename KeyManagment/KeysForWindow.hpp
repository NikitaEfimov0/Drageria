//
// Created by Никита Ефимов on 02.12.2021.
//

#ifndef MVC_MVP_KEYSFORWINDOW_HPP
#define MVC_MVP_KEYSFORWINDOW_HPP
#include "SFML/Graphics.hpp"
template<sf::Keyboard::Key T>
class KeysForWindow{
public:
    sf::Keyboard::Key returnExit(){
        return T;
    }
};
#endif //MVC_MVP_KEYSFORWINDOW_HPP
