//
// Created by Никита Ефимов on 21.10.2021.
//

#ifndef MVC_MVP_HERODRAW_HPP
#define MVC_MVP_HERODRAW_HPP
#include "ObjectDraw.hpp"
#include "../Objects/Hero.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>
#include "../Board/Cell.hpp"
#include "FireBallDraw.hpp"
#include "../Objects/FireBall.hpp"
#include "../KeyManagment/KeyReader.hpp"
class HeroDraw:public ObjectDraw{
    Hero* hero;
    Cell** &array;
    std::vector<FireBallDraw*>balls;
    int saveDirect;
    bool if_shooted;
    KeyReader* keyReader;
public:
    HeroDraw(Cell** &arr, int h, int w);
    void draw(sf::RenderWindow& window);
    void set_graphic();
    void move(float time);
    void collision();
    bool check_drawable();
    Object* returnObject(){return hero;}
    void check();
    Observer* returnObsFromObj();
    //void get_arrayofcell(Cell** array, int x, int y){};
};


#endif //MVC_MVP_HERODRAW_HPP
