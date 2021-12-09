//
// Created by Никита Ефимов on 02.12.2021.
//

#ifndef MVC_MVP_WORMFACTORY_HPP
#define MVC_MVP_WORMFACTORY_HPP
#include "../ObjectsDraw/WormDraw.hpp"
#include "Factory.hpp"
class WormFactory: public Factory{
    WormDraw* wormDraw;
public:
    WormFactory(Cell** arr, int w, int h) {
        array = arr;
        x = w;
        y = h;

    }
    ObjectDraw* createObjectDraw(){
        wormDraw = new WormDraw(array, x, y);
        return wormDraw;
    }
};


#endif //MVC_MVP_WORMFACTORY_HPP
