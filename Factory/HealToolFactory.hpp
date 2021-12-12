//
// Created by Никита Ефимов on 11.12.2021.
//

#ifndef MVC_MVP_HEALTOOLFACTORY_HPP
#define MVC_MVP_HEALTOOLFACTORY_HPP
#include "../ObjectsDraw/HealToolDraw.hpp"
#include "Factory.hpp"
class HealToolFactory: public Factory{
    HealToolDraw* healTool;
public:
    HealToolFactory(Cell** arr, int w, int h, bool L) {
        array = arr;
        x = w;
        y = h;
        Load = L;
    }
    ObjectDraw* createObjectDraw(){
        healTool = new HealToolDraw(array, x, y, Load);
        return healTool;
    }
};
#endif //MVC_MVP_HEALTOOLFACTORY_HPP
