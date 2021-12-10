//
// Created by Никита Ефимов on 21.11.2021.
//

#ifndef MVC_MVP_MEDIATOR_HPP
#define MVC_MVP_MEDIATOR_HPP
#include "../Rules/RuleII.hpp"
#include "../Rules/RuleI.hpp"
#include "../MainFiles/Game.hpp"
#include "../MainFiles/Arbitrator.hpp"
#include "MedInterface.hpp"
#include "../Rules/AmountOfObjects.hpp"
#include "../Menu/Menu.hpp"
class Mediator: public MedInterface{
    Arbitrator* arbitrator;
    Game<RuleII<10, 10>>* game;
    AmountOfObjects<1, 1, 1> am;
    Menu* menu = new Menu(this);
public:
    Mediator(){

        game = new Game<RuleII<10, 10>>(this);
        Initiate();
    }
    void Initiate(){
        menu->checkChose();
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
        if(wantToPlay == 1){
            arbitrator = new Arbitrator(12, 12, this);
            arbitrator->start_working(am.returnArchers(), am.returnWorms(), am.returnDragons());
        }
    }
};

#endif //MVC_MVP_MEDIATOR_HPP
