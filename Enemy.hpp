//
// Created by Никита Ефимов on 03.11.2021.
//

#ifndef MVC_MVP_ENEMY_HPP
#define MVC_MVP_ENEMY_HPP
#include "Creature.hpp"
class Enemy:public Creature {
public:
    Enemy(){
        x = 0;
        y = 0;
        speed = 0;
        health = 0;
        damage = 0;
    }
    Enemy(int w, int h){
        x = float(w);
        y = float(h);
        speed = 0;
        health = 0;
        damage = 0;
    }
    void fight(Object* object){};

};


#endif //MVC_MVP_ENEMY_HPP
