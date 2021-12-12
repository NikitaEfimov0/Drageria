//
// Created by Никита Ефимов on 08.11.2021.
//

#ifndef MVC_MVP_SUPERHEALTOOLDRAW_HPP
#define MVC_MVP_SUPERHEALTOOLDRAW_HPP
#include "../Objects/SuperHealTool.hpp"
#include "ObjectDraw.hpp"

class SuperHealToolDraw:public ObjectDraw {
    SuperHealTool* superHealTool;
    Cell**& array;
public:
    SuperHealToolDraw(Cell**& arr, int w, int h, bool Load);
    void draw(sf::RenderWindow &window);
    virtual void set_graphic();
    bool check_drawable();
    void SetRandomPosition(int w, int h);
};


#endif //MVC_MVP_SUPERHEALTOOLDRAW_HPP
