//
// Created by Никита Ефимов on 17.11.2021.
//

#ifndef MVC_MVP_RULEI_HPP
#define MVC_MVP_RULEI_HPP
#include "Rule.hpp"
template<int a>
class RuleI:public Rule{
    int score;
    int scoreNow;
    bool died;
    std::pair<bool, bool> res;
public:
    RuleI(){
        score = a;
        scoreNow = 0;
        died = false;
    }
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
//    ~RuleI(){
//        scoreNow = 0;
//        died = false;
//    }
};
#endif //MVC_MVP_RULEI_HPP
