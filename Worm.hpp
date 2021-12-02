//
// Created by Никита Ефимов on 06.11.2021.
//

#ifndef MVC_MVP_WORM_HPP
#define MVC_MVP_WORM_HPP
#include "Enemy.hpp"

class Worm:public Enemy {
public:
    Worm();
    Worm(int w, int h);
    void fight(Object* object);
};


#endif //MVC_MVP_WORM_HPP
