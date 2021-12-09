//
// Created by Никита Ефимов on 21.10.2021.
//

#ifndef MVC_MVP_HERO_HPP
#define MVC_MVP_HERO_HPP
#include "Creature.hpp"

class Hero: public Creature{
    int kills;
    bool reachedFinish;
public:
    Hero();
    Hero(int x, int y);
    void notify();
    int returnKills();
    void setKills();
    void setF();
    bool returnF();
    Observer* returnConcrObs();
};


#endif //MVC_MVP_HERO_HPP
