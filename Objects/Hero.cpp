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
    observer.push_back(new HeroSave(this));
    reachedFinish = false;
}

Hero::Hero(int i, int j, bool Load){

    observer.push_back(new HeroSave(this));
    if(Load)
        observer[0]->update(1);
    else{
        x = (float)i;
        y = (float)j;
        kills = 0;
        speed = 0.0015;
        damage = 30;
        health = 40;

    }
    speed = 0.0015;
    damage = 30;
    reachedFinish = false;
    observer.push_back(new Observer(this));
    observer.push_back(new HeroStatistic(this));
//    observer.push_back(new Observer(this));
//    observer.push_back(new HeroStatistic(this));
//    observer.push_back(new HeroSave(this));

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
    return observer[2];
}

void Hero::notify() {
    observer[1]->update(1);
    observer[2]->update();
    observer[0]->update(0);
}

int Hero::returnMaxHealth(){return maxHealth;}