//
// Created by Никита Ефимов on 06.11.2021.
//

#ifndef MVC_MVP_HEALTOOL_HPP
#define MVC_MVP_HEALTOOL_HPP
#include "Tool.hpp"

class HealTool:public Tool {
    int healing;
    bool used;
public:
    HealTool(){
        x = 0;
        y = 0;
        healing = 10;
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


#endif //MVC_MVP_HEALTOOL_HPP
