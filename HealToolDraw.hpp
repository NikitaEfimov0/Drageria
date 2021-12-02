//
// Created by Никита Ефимов on 06.11.2021.
//

#ifndef MVC_MVP_HEALTOOLDRAW_HPP
#define MVC_MVP_HEALTOOLDRAW_HPP
#include "ObjectDraw.hpp"
#include "HealTool.hpp"
#include "Cell.hpp"
class HealToolDraw:public ObjectDraw {
    HealTool* healTool;
    Cell**& array;
public:
    HealToolDraw(Cell**& arr, int w, int h);
    void draw(sf::RenderWindow &window);
    virtual void set_graphic();
    bool check_drawable();
    void SetRandomPosition(int w, int h);
};


#endif //MVC_MVP_HEALTOOLDRAW_HPP
