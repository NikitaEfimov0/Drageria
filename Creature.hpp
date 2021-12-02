//
// Created by Никита Ефимов on 21.10.2021.
//

#ifndef MVC_MVP_CREATURE_HPP
#define MVC_MVP_CREATURE_HPP
#include "Object.hpp"
#include "Observer.hpp"
#include "HeroStatistic.hpp"
#include <vector>
class Creature:public Object{
protected:
    std::vector<Observer*> observer;
    int health, damage;
    float speed;
public:
    Creature():health(20), damage(20), speed(1){};
    int return_health(){return health;}
    int return_damage(){return damage;}
    float return_speed(){return speed;}
    void set_speed(int i){speed = i;}
    void set_health(int i){health = i;}
    void set_damage(int i){damage = i;}
    void returnConcrObs(){};
};


#endif //MVC_MVP_CREATURE_HPP
