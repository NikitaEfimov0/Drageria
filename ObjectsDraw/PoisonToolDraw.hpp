//
// Created by Никита Ефимов on 08.11.2021.
//

#ifndef MVC_MVP_POISONTOOLDRAW_HPP
#define MVC_MVP_POISONTOOLDRAW_HPP
#include "../Objects/PoisonTool.hpp"
#include "ObjectDraw.hpp"

class PoisonToolDraw:public ObjectDraw {
    PoisonTool* poisonTool;
    Cell**& array;
public:
    PoisonToolDraw(Cell**& arr, int w, int h, bool Load, int num);
    void draw(sf::RenderWindow &window);
    virtual void set_graphic();
    bool check_drawable();
    void SetRandomPosition(int w, int h);
};


#endif //MVC_MVP_POISONTOOLDRAW_HPP
