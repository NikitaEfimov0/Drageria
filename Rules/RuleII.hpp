//
// Created by Никита Ефимов on 17.11.2021.
//

#ifndef MVC_MVP_RULEII_HPP
#define MVC_MVP_RULEII_HPP
#include "Rule.hpp"
template<int x, int y>
class RuleII:public Rule{
    std::pair<int, int>f;
    std::pair<int, int>tmp;
    bool died;
    std::pair<bool, bool> res;
public:
    RuleII(){
        f = {x, y};
        died = false;
    }
    std::pair<bool, bool> check(){
        //std::cout<<died<<std::endl;
        if(died){
            //std::cout<<"died\n";
            res.second = true;
            died = false;
            return res;
        }
        if(f == tmp){
            res.first = true;
            return res;
        }
        res.first = false;
        res.second = false;
        return res;
    }
    void getCurrentState(HeroStatistic* state){
        //std::cout<<"health: "<<state->returnCurrentHealth()<<std::endl;
         if(state->returnCurrentHealth()<=0){
             died = true;
         }
         else {
             died = false;
             tmp = state->returnCurrentCoord();
         }

    }
};

#endif //MVC_MVP_RULEII_HPP
