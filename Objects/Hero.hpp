//
// Created by Никита Ефимов on 21.10.2021.
//

#ifndef MVC_MVP_HERO_HPP
#define MVC_MVP_HERO_HPP
#include "Creature.hpp"
#include "../Serialisation/HeroSave.hpp"
class Hero: public Creature{
    int kills;
    bool reachedFinish;
    int maxHealth = 40;
public:
    Hero();
    Hero(int x, int y, bool Load);
    void notify();
    int returnKills();
    void setKills();
    void set_score(int i){kills = i;}
    void setF();
    bool returnF();
    int returnMaxHealth();
    Observer* returnConcrObs();
};


#endif //MVC_MVP_HERO_HPP
