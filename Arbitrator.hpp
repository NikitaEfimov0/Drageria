//
// Created by Никита Ефимов on 19.10.2021.
//

#ifndef MVC_MVP_ARBITRATOR_HPP
#define MVC_MVP_ARBITRATOR_HPP
#include "Board.hpp"
#include "SFML/Graphics.hpp"
#include "ObjectDraw.hpp"
#include "BoardDraw.hpp"
#include "HeroDraw.hpp"
#include "FireBallDraw.hpp"
#include "Enemy.hpp"
#include "ArcherDraw.hpp"
#include "WormDraw.hpp"
#include "DragonDraw.hpp"
#include "HealToolDraw.hpp"
#include "PoisonToolDraw.hpp"
#include "SuperHealToolDraw.hpp"
#include "PresentStat.hpp"
#include "Finish.hpp"
#include "KeyManagment/KeyReaderForWindow.hpp"
#include "MedInterface.hpp"
#include "Factory/ArcherFactory.hpp"
#include "Factory/WormFactory.hpp"
#include "Factory/DragonFactory.hpp"
#include <vector>
class Arbitrator {
    Finish* finish;
    MedInterface* mediator;
    Board* MainBoard;
    PresentStat* StatPresenter;
    sf::RenderWindow* MainWindow;
    std::vector<ObjectDraw*>objects;
    KeyReaderForWindow keys;
    bool isFinish;
    bool isWin;

public:
    ~Arbitrator();
    Arbitrator(int h, int w, MedInterface* med);
    void start_working(int a, int w, int d);
    void update_statement();
    void present();
    void check_death();
    HeroStatistic* returnStats();
    void win();
    void lose();
    void setIsFinish(){isFinish = true;}
    void changeIsWin(){isWin = true;}
    void exit();
};


#endif //MVC_MVP_ARBITRATOR_HPP
