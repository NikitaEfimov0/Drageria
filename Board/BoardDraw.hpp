//
// Created by Никита Ефимов on 19.10.2021.
//

#ifndef MVC_MVP_BOARDDRAW_HPP
#define MVC_MVP_BOARDDRAW_HPP
#include "../ObjectsDraw/ObjectDraw.hpp"
#include "Cell.hpp"
class BoardDraw:public ObjectDraw {
    Cell** arr;
    int h, w;
public:
    BoardDraw();
    void set_graphic();
    void draw(sf::RenderWindow& window);
    void get_arrayofcell(Cell**array, int x, int y);
};


#endif //MVC_MVP_BOARDDRAW_HPP
