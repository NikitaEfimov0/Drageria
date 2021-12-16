//
// Created by Никита Ефимов on 02.12.2021.
//

#ifndef MVC_MVP_DRAGONFACTORY_HPP
#define MVC_MVP_DRAGONFACTORY_HPP
#include "Factory.hpp"
#include "../ObjectsDraw/DragonDraw.hpp"
class DragonFactory:public Factory{
    DragonDraw* dragonDraw;
public:
    DragonFactory(Cell** arr, int w, int h, bool L) {
        array = arr;
        x = w;
        y = h;
        Load = L;
    }
    ObjectDraw* createObjectDraw(int ind){
        dragonDraw = new DragonDraw(array, x, y, Load, ind);
        return dragonDraw;
    }
};
#endif //MVC_MVP_DRAGONFACTORY_HPP
