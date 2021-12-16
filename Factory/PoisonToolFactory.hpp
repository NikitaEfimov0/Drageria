//
// Created by Никита Ефимов on 11.12.2021.
//

#ifndef MVC_MVP_POISONTOOLFACTORY_HPP
#define MVC_MVP_POISONTOOLFACTORY_HPP
#include "../ObjectsDraw/PoisonToolDraw.hpp"
#include "Factory.hpp"
class PoisonToolFactory: public Factory {
    PoisonToolDraw *poisonTool;
public:
    PoisonToolFactory(Cell **arr, int w, int h, bool L) {
        array = arr;
        x = w;
        y = h;
        Load = L;
    }

    ObjectDraw *createObjectDraw(int ind) {
        poisonTool = new PoisonToolDraw(array, x, y, Load, ind);
        return poisonTool;
    }
};
#endif //MVC_MVP_POISONTOOLFACTORY_HPP
