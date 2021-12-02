//
// Created by Никита Ефимов on 17.11.2021.
//

#ifndef MVC_MVP_RULEI_HPP
#define MVC_MVP_RULEI_HPP
#include "Rule.hpp"
template<int a>
class RuleI:public Rule{
    int score = a;
    int scoreNow = 0;
    bool died = false;
    std::pair<bool, bool> res;
public:
    std::pair<bool, bool> check(){
        if(died){
            res.first = false;
            res.second = true;
            return res;
        }
        if(score <=scoreNow) {
            res.first = true;
            if(died)
                res.second = true;
            else
                res.second = false;
            return res;
        }
        res.first = false;
        res.second = false;
        return res;

    }
    void getCurrentState(HeroStatistic* state){
        scoreNow = state->returnCurrentScore();
        if(state->returnCurrentHealth()<=0)
            died = true;
    }
};
#endif //MVC_MVP_RULEI_HPP
