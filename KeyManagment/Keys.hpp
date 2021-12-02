//
// Created by Никита Ефимов on 30.11.2021.
//

#ifndef MVC_MVP_KEYS_HPP
#define MVC_MVP_KEYS_HPP
#include "SFML/Graphics.hpp"
using namespace sf;
template <Keyboard::Key F = Keyboard::Up, Keyboard::Key B = Keyboard::Down, Keyboard::Key L = Keyboard::Left, Keyboard::Key R = Keyboard::Right, Keyboard::Key Sh = Keyboard::F>
class Keys{
public:
    Keyboard::Key getF(){return F;}
    Keyboard::Key getB(){return B;}
    Keyboard::Key getL(){return L;}
    Keyboard::Key getR(){return R;}
    Keyboard::Key getSh(){return Sh;}
};
#endif //MVC_MVP_KEYS_HPP
