//
// Created by Никита Ефимов on 06.11.2021.
//

#ifndef MVC_MVP_WORMDRAW_HPP
#define MVC_MVP_WORMDRAW_HPP
#include "ObjectDraw.hpp"
#include "Worm.hpp"
class WormDraw:public ObjectDraw {
    Worm* worm;
    Cell** &arr;
public:
    WormDraw(Cell **&array, int w, int h);
    void draw(sf::RenderWindow &window);
    virtual void set_graphic();
    virtual  void move(float time);
    void collision();
    bool check_drawable();
    void SetRandomPosition(Cell** array, int w, int h);
    Object* returnObject(){return worm;}
};


#endif //MVC_MVP_WORMDRAW_HPP
