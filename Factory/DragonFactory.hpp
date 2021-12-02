//
// Created by Никита Ефимов on 02.12.2021.
//

#ifndef MVC_MVP_DRAGONFACTORY_HPP
#define MVC_MVP_DRAGONFACTORY_HPP
#include "Factory.hpp"
#include "../DragonDraw.hpp"
class DragonFactory:public Factory{
    DragonDraw* dragonDraw;
public:
    DragonFactory(Cell** arr, int w, int h) {
        array = arr;
        x = w;
        y = h;

    }
    ObjectDraw* createObjectDraw(){
        dragonDraw = new DragonDraw(array, x, y);
        return dragonDraw;
    }
};
#endif //MVC_MVP_DRAGONFACTORY_HPP
