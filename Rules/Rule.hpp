//
// Created by Никита Ефимов on 17.11.2021.
//

#ifndef MVC_MVP_RULE_HPP
#define MVC_MVP_RULE_HPP
#include "../Observers/HeroStatistic.hpp"
class Rule{
public:
    Rule(){
    }
//    virtual ~Rule(){}
    virtual std::pair<bool, bool> check() = 0;
    virtual void getCurrentState(HeroStatistic* state){};
};
#endif //MVC_MVP_RULE_HPP
