//
// Created by Никита Ефимов on 02.12.2021.
//

#ifndef MVC_MVP_ARCHERFACTORY_HPP
#define MVC_MVP_ARCHERFACTORY_HPP
#include "Factory.hpp"
#include "../ObjectsDraw/ArcherDraw.hpp"
class ArcherFactory:public Factory{
    ArcherDraw* archerDraw;
public:
    ArcherFactory(Cell** arr, int w, int h, bool L) {
        array = arr;
        x = w;
        y = h;
        Load = L;

    }
    ObjectDraw* createObjectDraw(int ind){
        archerDraw = new ArcherDraw(array, x, y, Load, ind);
        return archerDraw;
    }
};
#endif //MVC_MVP_ARCHERFACTORY_HPP
