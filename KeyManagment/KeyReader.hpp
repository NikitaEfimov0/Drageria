//
// Created by Никита Ефимов on 30.11.2021.
//

#ifndef MVC_MVP_KEYREADER_HPP
#define MVC_MVP_KEYREADER_HPP
#include "Keys.hpp"
#include "SFML/Graphics.hpp"
using namespace sf;
class KeyReader{
    Keys<Keyboard::W, Keyboard::S, Keyboard::A, Keyboard::D, Keyboard::Space> keys;
public:
    bool checkF(){
        if(Keyboard::isKeyPressed(keys.getF())){
            return true;
        }
        return false;
    }
    bool checkB(){
        if(Keyboard::isKeyPressed(keys.getB())) {
            return true;
        }
        return false;
    }
    bool checkL(){
        if(Keyboard::isKeyPressed(keys.getL())) {
            return true;
        }
        return false;
    }
    bool checkR(){
        if(Keyboard::isKeyPressed(keys.getR())) {
            return true;
        }
        return false;
    }
    bool checkSh(){
        if(Keyboard::isKeyPressed(keys.getSh()))
            return true;
        return false;
    }

};

#endif //MVC_MVP_KEYREADER_HPP
