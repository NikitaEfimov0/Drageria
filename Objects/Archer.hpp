//
// Created by Никита Ефимов on 03.11.2021.
//

#ifndef MVC_MVP_ARCHER_HPP
#define MVC_MVP_ARCHER_HPP
#include "Enemy.hpp"
#include "Creature.hpp"
#include "../Serialisation/ArcherSave.hpp"
class Archer: public Enemy{
public:
    Archer(bool Load);
    Archer(int w, int h);
    void fight(Object* object);
    void notify();
};


#endif //MVC_MVP_ARCHER_HPP
