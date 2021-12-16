//
// Created by Никита Ефимов on 06.11.2021.
//

#ifndef MVC_MVP_DRAGONDRAW_HPP
#define MVC_MVP_DRAGONDRAW_HPP
#include "ObjectDraw.hpp"
#include "../Objects/Dragon.hpp"
class DragonDraw :public ObjectDraw{
    Dragon* dragon;
    Cell** &arr;
public:
    DragonDraw(Cell **&array, int w, int h, bool Load, int num);
    void draw(sf::RenderWindow &window);
    virtual void set_graphic();
    virtual  void move(float time);
    void collision();
    void SetRandomPosition(Cell** array, int w, int h);
    bool check_drawable();
    Object* returnObject(){return dragon;}
};


#endif //MVC_MVP_DRAGONDRAW_HPP
