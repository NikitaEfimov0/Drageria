//
// Created by Никита Ефимов on 23.11.2021.
//

#ifndef MVC_MVP_HEROSTATISTIC_HPP
#define MVC_MVP_HEROSTATISTIC_HPP
#include "../Objects/Object.hpp"
#include "Observer.hpp"
#include <iostream>
class HeroStatistic:public Observer {
    int CurrentHealth;
    std::pair<float, float> CurrentCoord;
    int CurrentScore;
    bool isReached;
public:
    HeroStatistic(Object* publisher){
        observable = publisher;
        isReached = observable->returnF();
        CurrentHealth = observable->return_health();
        CurrentScore = 0;
        CurrentCoord.first = observable->return_x();
        CurrentCoord.second = observable->return_y();
    }
    void update(){
        CurrentHealth = observable->return_health();
        CurrentScore=observable->returnKills()*50;
        CurrentCoord.first = observable->return_x();
        CurrentCoord.second = observable->return_y();
        isReached = observable->returnF();
    }
    int returnCurrentHealth(){return CurrentHealth;}
    int returnCurrentScore(){return CurrentScore;}
    std::pair<float, float> returnCurrentCoord(){return CurrentCoord;}
//    bool returnIsReached(){return isReached;}
};


#endif //MVC_MVP_HEROSTATISTIC_HPP
