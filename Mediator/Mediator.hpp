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
#include "../Menu/PauseMenu.hpp"
#include "../Data/Cleaner.hpp"
class Mediator: public MedInterface{
    Arbitrator* arbitrator;
    Game<RuleII<10, 10>>* game;
    AmountOfObjects<1, 1, 1, 1, 1, 1> am;
    Menu* menu;
    PauseMenu* pauseMenu;
    Cleaner cleaner;
public:
    Mediator(){
        game = new Game<RuleII<10, 10>>(this);
        Initiate();
    }
    void Initiate(){
        menu = new Menu(this);
        menu->checkChose();
    }
    void InitiatePause(){
        pauseMenu = new PauseMenu(this);
        pauseMenu->pause();
    }
    void notify(){
        game->checkRule(arbitrator->returnStats());
    }
    void notify(bool worl){
        arbitrator->setIsFinish();
        if(worl){
            arbitrator->changeIsWin(true);
        }
        else{
            arbitrator->changeIsWin(false);
        }
    }
    void notify(int wantToPlay){
        if(wantToPlay == 1){
            arbitrator = new Arbitrator(12, 12, this);
            arbitrator->start_working(returnAm(), false);
        }
        if(wantToPlay == 2){
            arbitrator = new Arbitrator(12, 12, this);
            if(cleaner.findFile()) {
                arbitrator->start_working(returnAm(), true);
            }
            else{
                arbitrator->start_working(returnAm(), false);
            }
        }
        if(wantToPlay == 3)
            InitiatePause();
        if(wantToPlay == 5){
            Initiate();
        }


    }
    std::vector<int>returnAm(){
        std::vector<int>n = {am.returnArchers(), am.returnWorms(), am.returnDragons(), am.returnHealTools(), am.returnPoisonTool(), am.returnSupHealTool()};
        return n;
    }
};

#endif //MVC_MVP_MEDIATOR_HPP
