//
// Created by Никита Ефимов on 06.11.2021.
//

#ifndef MVC_MVP_DRAGON_HPP
#define MVC_MVP_DRAGON_HPP
#include "Enemy.hpp"
#include "../Serialisation/DragonSave.hpp"
class Dragon:public Enemy {
public:
    Dragon(bool Load, int num);
    Dragon(int w, int h);
    void fight(Object* object);
    void notify(){observer[0]->update(0);}
};


#endif //MVC_MVP_DRAGON_HPP
