//
// Created by Никита Ефимов on 08.11.2021.
//

#ifndef MVC_MVP_SUPERHEALTOOL_HPP
#define MVC_MVP_SUPERHEALTOOL_HPP
#include "Tool.hpp"
#include "../Serialisation/SuperHealSave.hpp"
class SuperHealTool:public Tool{
    int healing;
    bool used;
public:
    SuperHealTool(bool Load){
        x = 0;
        y = 0;
        healing = 25;
        used = false;
        observer.push_back(new SuperHealSave(this));
        if(Load)
            observer[0]->update(1);
    }
    void usage(Object* hero){
        hero->set_health(hero->return_health()+healing);
        if(hero->return_health()>hero->returnMaxHealth())
            hero->set_health(hero->returnMaxHealth());
        used = true;
    }
    bool return_used(){
        return used;
    }
    void notify(){observer[0]->update(0);}
    void set_used(bool u){used = u;}
};
#endif //MVC_MVP_SUPERHEALTOOL_HPP
