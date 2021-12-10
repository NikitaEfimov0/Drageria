//
// Created by Никита Ефимов on 06.11.2021.
//

#include "Dragon.hpp"
Dragon::Dragon() {
    x = 0;
    y = 0;
    health = 40;
    damage = 40;
    speed = 0.001;
    observer.push_back(new DragonSave(this));
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