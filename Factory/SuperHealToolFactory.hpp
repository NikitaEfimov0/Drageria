//
// Created by Никита Ефимов on 11.12.2021.
//

#ifndef MVC_MVP_SUPERHEALTOOLFACTORY_HPP
#define MVC_MVP_SUPERHEALTOOLFACTORY_HPP
#include "../ObjectsDraw/SuperHealToolDraw.hpp"
#include "Factory.hpp"
class SuperHealToolFactory: public Factory {
    SuperHealToolDraw *superHealTool;
public:
    SuperHealToolFactory(Cell **arr, int w, int h, bool L) {
        array = arr;
        x = w;
        y = h;
        Load = L;
    }

    ObjectDraw *createObjectDraw() {
        superHealTool = new SuperHealToolDraw(array, x, y, Load);
        return superHealTool;
    }
};
#endif //MVC_MVP_SUPERHEALTOOLFACTORY_HPP
