//
// Created by Никита Ефимов on 06.11.2021.
//

#ifndef MVC_MVP_DRAGON_HPP
#define MVC_MVP_DRAGON_HPP
#include "Enemy.hpp"

class Dragon:public Enemy {
public:
    Dragon();
    Dragon(int w, int h);
    void fight(Object* object);
};


#endif //MVC_MVP_DRAGON_HPP
