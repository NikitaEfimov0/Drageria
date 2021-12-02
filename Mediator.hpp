//
// Created by Никита Ефимов on 21.11.2021.
//

#ifndef MVC_MVP_MEDIATOR_HPP
#define MVC_MVP_MEDIATOR_HPP
#include "Rules/RuleII.hpp"
#include "Rules/RuleI.hpp"
#include "Game.hpp"
#include "Arbitrator.hpp"
#include "MedInterface.hpp"
#include "Rules/AmountOfObjects.hpp"
class Mediator: public MedInterface{
    Arbitrator* arbitrator;
    Game<RuleII<10, 10>>* game;
    AmountOfObjects<1, 1, 1> am;
public:
    Mediator(){
        arbitrator = new Arbitrator(12, 12, this);
        game = new Game<RuleII<10, 10>>(this);
        Initiate();
    }
    void Initiate(){
        arbitrator->start_working(am.returnArchers(), am.returnWorms(), am.returnDragons());
    }
    void notify(){
        game->checkRule(arbitrator->returnStats());
    }
    void notify(bool worl){
        arbitrator->setIsFinish();
        if(worl){
            arbitrator->changeIsWin();
        }
    }
    void notify(int wantToPlay){
//        std::cout<<"hi hter";
//        if(wantToPlay==1) {
//            arbitrator->exit();
////            delete arbitrator;
//            arbitrator = new Arbitrator(12, 12);
//            Initiate();
//        }
    }
};

#endif //MVC_MVP_MEDIATOR_HPP
