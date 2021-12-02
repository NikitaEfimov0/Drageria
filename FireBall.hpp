//
// Created by Никита Ефимов on 01.11.2021.
//

#ifndef MVC_MVP_FIREBALL_HPP
#define MVC_MVP_FIREBALL_HPP
#include "Object.hpp"

class FireBall:public Object {
    float speed;
    int direction;
    float time;
    bool life;
    int damage;
    bool kill;
public:
    FireBall(float w, float h, int dir, float t){
        x = w;
        y = h;
        direction = dir;
        speed = 0.015;
        time = t;
        life = true;
        damage = 5;
        kill = false;
    }
    FireBall& operator=(const FireBall& obj){
        if(this!=&obj){
            x = obj.x;
            y = obj.y;
            direction = obj.direction;
            speed = obj.speed;
            time = obj.time;
            life = obj.life;
            damage = obj.damage;
            kill = obj.kill;
        }
        return *this;
    }
    float return_speed(){
        return speed;
    }
    float return_time(){
        return time;
    }
    int return_direction(){
        return direction;
    }
    bool return_life(){
        return life;
    }
    void set_life(bool change){
        life = change;
    }
    int return_damage(){
        return damage;
    }
    void setKill(){
        kill = true;
    }
    bool returnKill(){return kill;}
};


#endif //MVC_MVP_FIREBALL_HPP
