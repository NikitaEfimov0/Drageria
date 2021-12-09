//
// Created by Никита Ефимов on 08.11.2021.
//

#ifndef MVC_MVP_SUPERHEALTOOL_HPP
#define MVC_MVP_SUPERHEALTOOL_HPP
#include "Tool.hpp"
class SuperHealTool:public Tool{
    int healing;
    bool used;
public:
    SuperHealTool(){
        x = 0;
        y = 0;
        healing = 25;
        used = false;
    }
    void usage(Object* hero){
        hero->set_health(hero->return_health()+healing);
        used = true;
    }
    bool return_used(){
        return used;
    }
};
#endif //MVC_MVP_SUPERHEALTOOL_HPP
