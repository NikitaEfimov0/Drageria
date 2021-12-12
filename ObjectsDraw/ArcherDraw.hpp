//
// Created by Никита Ефимов on 04.11.2021.
//

#ifndef MVC_MVP_ARCHERDRAW_HPP
#define MVC_MVP_ARCHERDRAW_HPP
#include "ObjectDraw.hpp"
#include "../Objects/Archer.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>
#include "../Board/Cell.hpp"
class ArcherDraw:public ObjectDraw {
    Archer* archer;
    Cell** &arr;
public:
    ArcherDraw(Cell **&array, int w, int h, bool Load);
    void draw(sf::RenderWindow &window);
    virtual void set_graphic();
    virtual  void move(float time);
    void collision();
    bool check_drawable();
    void SetRandomPosition(Cell** array, int w, int h);
    Object* returnObject(){return archer;}
};


#endif //MVC_MVP_ARCHERDRAW_HPP
