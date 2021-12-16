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
    WormFactory(Cell** arr, int w, int h, bool L) {
        array = arr;
        x = w;
        y = h;
        Load = L;
    }
    ObjectDraw* createObjectDraw(int ind){
        wormDraw = new WormDraw(array, x, y, Load, ind);
        return wormDraw;
    }
};


#endif //MVC_MVP_WORMFACTORY_HPP
