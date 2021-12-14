//
// Created by Никита Ефимов on 19.10.2021.
//

#ifndef MVC_MVP_ARBITRATOR_HPP
#define MVC_MVP_ARBITRATOR_HPP
#include "../Board/Board.hpp"
#include "SFML/Graphics.hpp"
#include "../ObjectsDraw/ObjectDraw.hpp"
#include "../Board/BoardDraw.hpp"
#include "../ObjectsDraw/HeroDraw.hpp"
#include "../ObjectsDraw/FireBallDraw.hpp"
#include "../Objects/Enemy.hpp"
#include "../ObjectsDraw/ArcherDraw.hpp"
#include "../ObjectsDraw/WormDraw.hpp"
#include "../ObjectsDraw/DragonDraw.hpp"
#include "../ObjectsDraw/HealToolDraw.hpp"
#include "../ObjectsDraw/PoisonToolDraw.hpp"
#include "../ObjectsDraw/SuperHealToolDraw.hpp"
#include "../Observers/PresentStat.hpp"
#include "Finish.hpp"
#include "../KeyManagment/KeyReaderForWindow.hpp"
#include "../Mediator/MedInterface.hpp"
#include "../Factory/ArcherFactory.hpp"
#include "../Factory/WormFactory.hpp"
#include "../Factory/DragonFactory.hpp"
#include "../Factory/SuperHealToolFactory.hpp"
#include "../Factory/HealToolFactory.hpp"
#include "../Factory/PoisonToolFactory.hpp"
#include "../Data/Cleaner.hpp"
#include <vector>
enum class isWinState{
    NONE, Win, Lose
};
class Arbitrator {
    Finish* finish;
    MedInterface* mediator;
    Board* MainBoard;
    PresentStat* StatPresenter;
    sf::RenderWindow* MainWindow;
    std::vector<ObjectDraw*>objects;
    KeyReaderForWindow keys;
    bool isFinish;
    isWinState isWin;
    Cleaner cleaner;

public:
    ~Arbitrator();
    Arbitrator(int h, int w, MedInterface* med);
    void start_working(std::vector<int>am, bool Load);
    void update_statement();
    void present();
    void check_death();
    HeroStatistic* returnStats();
    void win();
    void lose();
    void setIsFinish(){isFinish = true;}
    void changeIsWin(bool w){
        if(w)
            isWin = isWinState::Win;
        else
            isWin = isWinState::Lose;
    }
    void exit();
};


#endif //MVC_MVP_ARBITRATOR_HPP
