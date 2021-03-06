//
// Created by Никита Ефимов on 03.11.2021.
//

#include "Archer.hpp"
Archer::Archer(bool Load, int num) {
    x = 0;
    y = 0;
    health = 10;
    damage = 10;
    speed = 0.0015;
    number = num;
    observer.push_back(new ArcherSave(this));
    if(Load)
        observer[0]->update(1);
}

Archer::Archer(int w, int h){
    x = (float)w;
    y = (float)h;
    health = 10;
    damage = 10;
    speed = 0.0015;
    //observer.push_back(new Observer(this));

}

void Archer::notify() {
    observer[0]->update(0);
}
void Archer::fight(Object* object) {
    health-=object->return_damage();
    object->set_health(object->return_health()-damage);
}
