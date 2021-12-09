//
// Created by Никита Ефимов on 01.11.2021.
//

#ifndef MVC_MVP_FIREBALLDRAW_HPP
#define MVC_MVP_FIREBALLDRAW_HPP
#include "ObjectDraw.hpp"
#include "../Objects/FireBall.hpp"
class FireBallDraw:public ObjectDraw {
    FireBall* fireball;
    Cell** &array;
public:
    FireBallDraw(FireBall* obj, Cell** &arr);
    void draw(sf::RenderWindow& window);
    void set_graphic();
    void move(float time);
    void collision();
    FireBall* return_fireball(){
        return fireball;
    }
};


#endif //MVC_MVP_FIREBALLDRAW_HPP
