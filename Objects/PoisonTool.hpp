//
// Created by Никита Ефимов on 08.11.2021.
//

#ifndef MVC_MVP_POISONTOOL_HPP
#define MVC_MVP_POISONTOOL_HPP
#include "Tool.hpp"
#include "../Serialisation/PoisonSave.hpp"
class PoisonTool:public Tool{
    int reducing;
    bool used;
public:
    PoisonTool(bool Load){
        x = 0;
        y = 0;
        reducing = 10;
        used = false;
        observer.push_back(new PoisonSave(this));
        if(Load)
            observer[0]->update(1);
    }
    void usage(Object* hero){
        hero->set_health(hero->return_health()-reducing);
        used = true;
    }
    bool return_used() {
        return used;
    }

    void notify(){observer[0]->update(0);}

    void set_used(bool u){used = u;}
};
#endif //MVC_MVP_POISONTOOL_HPP
