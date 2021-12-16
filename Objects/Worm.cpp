//
// Created by Никита Ефимов on 06.11.2021.
//

#include "Worm.hpp"
Worm::Worm(bool Load, int num) {
    x = 0;
    y = 0;
    health = 30;
    damage = 30;
    speed = 0.003;
    number = num;
    observer.push_back(new WormSave(this));
    if(Load)
        observer[0]->update(1);
}

Worm::Worm(int w, int h){
    x = (float)w;
    y = (float)h;
    health = 30;
    damage = 30;
    speed = 0.003;
    observer.push_back( new Observer(this));
}

void Worm::fight(Object* object) {
    health-=object->return_damage();
    object->set_health(object->return_health()-damage);

}