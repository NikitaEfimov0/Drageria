//
// Created by Никита Ефимов on 03.11.2021.
//

#ifndef MVC_MVP_ARCHER_HPP
#define MVC_MVP_ARCHER_HPP
#include "Enemy.hpp"
#include "Creature.hpp"
class Archer: public Enemy{
public:
    Archer();
    Archer(int w, int h);
    void fight(Object* object);
};


#endif //MVC_MVP_ARCHER_HPP