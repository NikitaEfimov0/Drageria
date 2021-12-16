//
// Created by Никита Ефимов on 21.10.2021.
//

#ifndef MVC_MVP_OBJECT_HPP
#define MVC_MVP_OBJECT_HPP
//#include "Mediator.hpp"
//#include "Rules/RuleI.hpp"
class Object {
protected:
    //Mediator<RuleI>mediator;
    float x, y;
    int number;
public:
    virtual ~Object(){}
    void set_x(float i){
        x = (float)i;
    }
    void set_y(float i){
        y = (float)i;
    }
    float return_x(){return x;}
    float return_y(){return y;}
    virtual float return_speed(){return 0;}
    virtual int return_damage(){return 0;}
    virtual int return_health(){return 0;}
    virtual void set_health(int change){}
    virtual void fight(Object* object){}
    virtual int returnKills(){return 0;}
    virtual void notify(){}
    virtual bool returnKill(){return false;}
    bool returnF(){return false;}
    virtual bool return_used(){return false;}
    virtual int returnNumber(){return number;}
    virtual int returnMaxHealth(){return 0;}
    virtual void set_used(bool u){}
    virtual void set_score(int i){}
};


#endif //MVC_MVP_OBJECT_HPP
