//
// Created by Никита Ефимов on 08.11.2021.
//

#ifndef MVC_MVP_POISONTOOL_HPP
#define MVC_MVP_POISONTOOL_HPP
#include "Tool.hpp"
class PoisonTool:public Tool{
    int reducing;
    bool used;
public:
    PoisonTool(){
        x = 0;
        y = 0;
        reducing = 10;
        used = false;
    }
    void usage(Object* hero){
        hero->set_health(hero->return_health()-reducing);
        used = true;
    }
    bool return_used(){
        return used;
    }
};
#endif //MVC_MVP_POISONTOOL_HPP
