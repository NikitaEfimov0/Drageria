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
    ArcherFactory(Cell** arr, int w, int h) {
        array = arr;
        x = w;
        y = h;

    }
    ObjectDraw* createObjectDraw(){
        archerDraw = new ArcherDraw(array, x, y);
        return archerDraw;
    }
};
#endif //MVC_MVP_ARCHERFACTORY_HPP
