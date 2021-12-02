//
// Created by Никита Ефимов on 17.11.2021.
//

#ifndef MVC_MVP_RULEII_HPP
#define MVC_MVP_RULEII_HPP
#include "Rule.hpp"
template<int x, int y>
class RuleII:public Rule{
    std::pair<int, int>f = {x, y};
    std::pair<int, int>tmp;
    bool died = false;
    std::pair<bool, bool> res;
public:
    std::pair<bool, bool> check(){
        if(died){
            res.second = true;
            return res;
        }
        if(f == tmp){
            res.second = died;
            res.first = true;
            return res;
        }
        res.first = false;
        res.second = false;
        return res;
    }
    void getCurrentState(HeroStatistic* state){
         if(state->returnCurrentHealth()<=0)
             died = true;
         tmp = state->returnCurrentCoord();
    }
};

#endif //MVC_MVP_RULEII_HPP
