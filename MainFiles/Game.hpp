//
// Created by Никита Ефимов on 20.11.2021.
//
#ifndef MVC_MVP_GAME_HPP
#define MVC_MVP_GAME_HPP
#include "../Mediator/MedInterface.hpp"
template<class R>
class Game {
    MedInterface* mediator;
    R* rule = new R();
public:
    Game(MedInterface* med):mediator(med){}
    void checkRule(HeroStatistic* state){
        if(rule->check().second)
            mediator->notify(false);
        if(rule->check().first){
            mediator->notify(true);
        }
        rule->getCurrentState(state);
    }
};
#endif //MVC_MVP_GAME_HPP
