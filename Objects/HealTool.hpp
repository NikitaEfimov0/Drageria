//
// Created by Никита Ефимов on 06.11.2021.
//

#ifndef MVC_MVP_HEALTOOL_HPP
#define MVC_MVP_HEALTOOL_HPP
#include "Tool.hpp"
#include "../Serialisation/HealSave.hpp"
class HealTool:public Tool {
    int healing;
    bool used;
public:
    HealTool(bool Load){
        x = 0;
        y = 0;
        healing = 10;
        used = false;
        observer.push_back(new HealSave(this));
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


#endif //MVC_MVP_HEALTOOL_HPP
