//
// Created by Никита Ефимов on 20.11.2021.
//
#ifndef MVC_MVP_GAME_HPP
#define MVC_MVP_GAME_HPP
#include "../Mediator/MedInterface.hpp"
template<class R>
class Game {
    MedInterface* mediator;
    R* rule;
public:
    Game(MedInterface* med):mediator(med){rule = new R();}
    void checkRule(HeroStatistic* state){
        rule->getCurrentState(state);
        //std::cout<<state->returnCurrentCoord().first<<' '<<state->returnCurrentCoord().second<<' '<<state->returnCurrentHealth()<<std::endl;
        if(rule->check().second) {
            //std::cout<<1<<std::endl;
            mediator->notify(false);
        }
        if(rule->check().first){
            std::cout<<2<<std::endl;
            mediator->notify(true);
        }

        //std::cout<<state->returnCurrentCoord().first<<' '<<state->returnCurrentCoord().second<<' '<<state->returnCurrentHealth()<<std::endl;

    }
    ~Game(){
        delete rule;
    }
};
#endif //MVC_MVP_GAME_HPP
