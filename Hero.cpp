//
// Created by Никита Ефимов on 21.10.2021.
//
#include "Hero.hpp"
Hero::Hero(){
    x = 0;
    y = 0;
    kills = 0;
    speed = 0.0015;
    damage = 30;
    health = 40;
    observer.push_back(new Observer(this));
    observer.push_back(new HeroStatistic(this));
    reachedFinish = false;
}

Hero::Hero(int i, int j){
    x = (float)i;
    y = (float)j;
    kills = 0;
    speed = 0.0015;
    damage = 30;
    health = 40;
    reachedFinish = false;
    observer.push_back(new Observer(this));
    observer.push_back(new HeroStatistic(this));
}
void Hero::setKills(){
    kills++;
}
int Hero::returnKills() {return kills;}

void Hero::setF(){
    reachedFinish = true;
}

bool Hero::returnF() {
    return reachedFinish;
}

Observer* Hero::returnConcrObs() {
    return observer[1];
}

void Hero::notify() {
    observer[0]->update(2);
    observer[1]->update();
}