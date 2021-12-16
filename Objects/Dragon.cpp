//
// Created by Никита Ефимов on 06.11.2021.
//

#include "Dragon.hpp"
Dragon::Dragon(bool Load, int num) {
    x = 0;
    y = 0;
    number = num;
    health = 40;
    damage = 40;
    speed = 0.001;
    observer.push_back(new DragonSave(this));
    if(Load)
        observer[0]->update(1);
}

Dragon::Dragon(int w, int h) {
    x = (float) w;
    y = (float) h;
    health = 40;
    damage = 40;
    speed = 0.001;
    observer.push_back(new DragonSave(this));
}
void Dragon::fight(Object* object) {
    health-=object->return_damage();
    object->set_health(object->return_health()-damage);
}