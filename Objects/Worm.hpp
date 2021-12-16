//
// Created by Никита Ефимов on 06.11.2021.
//

#ifndef MVC_MVP_WORM_HPP
#define MVC_MVP_WORM_HPP
#include "Enemy.hpp"
#include "../Serialisation/WormSave.hpp"
class Worm:public Enemy {
public:
    Worm(bool Load, int num);
    Worm(int w, int h);
    void fight(Object* object);
    void notify(){observer[0]->update(0);}
};


#endif //MVC_MVP_WORM_HPP
