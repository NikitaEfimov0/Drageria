//
// Created by Никита Ефимов on 19.10.2021.
//
#include "Arbitrator.hpp"
using namespace sf;

Arbitrator::Arbitrator(int h, int w, MedInterface* med) {
    MainBoard = new Board(h, w);
    MainWindow = new RenderWindow(VideoMode(w*185, h*185),"Drageria");
    objects.push_back(new BoardDraw());
    finish = new Finish();
    isFinish = false;
    isWin = isWinState::NONE;
    mediator = med;
}

void Arbitrator::start_working(std::vector<int>am, bool Load) {
        MainBoard->set_board();
        objects.push_back(new HeroDraw(MainBoard->return_array(), MainBoard->return_height(), MainBoard->return_width(), Load));
        StatPresenter = new PresentStat(objects[1]->returnObsFromObj());
        WormFactory wf(MainBoard->return_array(), MainBoard->return_width(), MainBoard->return_height(), Load);
        ArcherFactory af(MainBoard->return_array(), MainBoard->return_width(), MainBoard->return_height(), Load);
        DragonFactory df(MainBoard->return_array(), MainBoard->return_width(), MainBoard->return_height(), Load);
        HealToolFactory hf(MainBoard->return_array(), MainBoard->return_width(), MainBoard->return_height(), Load);
        PoisonToolFactory pf(MainBoard->return_array(), MainBoard->return_width(), MainBoard->return_height(), Load);
        SuperHealToolFactory shf(MainBoard->return_array(), MainBoard->return_width(), MainBoard->return_height(), Load);
        for (int i = 0; i < am[0]; i++) {
            objects.push_back(af.createObjectDraw(i));
        }
        for (int i = 0; i < am[1]; i++) {
            objects.push_back(wf.createObjectDraw(i));
        }
        for (int i = 0; i < am[2]; i++) {
            objects.push_back(df.createObjectDraw(i));
        }
        for(int i = 0; i < am[3]; i++){
            objects.push_back(hf.createObjectDraw(i));
        }
        for(int i = 0; i < am[4]; i++){
            objects.push_back(pf.createObjectDraw(i));
        }
        for(int i = 0; i < am[5]; i++){
            objects.push_back(shf.createObjectDraw(i));
        }
        objects[0]->set_graphic();
        objects[0]->get_arrayofcell(MainBoard->return_array(), MainBoard->return_height(), MainBoard->return_width());
    for(int i = 1; i< objects.size(); i++)
        objects[i]->set_graphic();
    update_statement();
}

void Arbitrator::check_death() {
    for(int i = 1; i < objects.size(); i++){
        if(!objects[i]->check_drawable()){
            //std::cout<<"deleted";
            objects.erase(objects.begin()+i);
        }
    }
}

HeroStatistic* Arbitrator::returnStats(){
   return StatPresenter->returnScore();
}

void Arbitrator::update_statement() {
    Clock clock;
    MainWindow->setFramerateLimit(60);
    while(MainWindow->isOpen()) {
        Event event;
        int time = clock.restart().asMilliseconds();
        while (MainWindow->pollEvent(event)) {
            if (event.type == event.Closed) {
                MainWindow->close();
            }
            if (event.type == event.KeyPressed) {
                if (keys.checkExit()) {
                    MainWindow->close();
                    if(!isFinish)
                        mediator->notify(3);
                    else {
                        cleaner.clean();
                        mediator->notify(5);
                    }
                    return;
                }
            }
        }
        if(!isFinish && isWin == isWinState::NONE) {
            mediator->notify();
        }
        //std::cout<<"suck dick\n";
        if (!isFinish) {
            for (int i = 1; i < objects.size(); i++)
                objects[i]->move(time);
            MainWindow->clear();
            check_death();
            for (int i = 0; i < objects.size(); i++) {
                objects[i]->draw(*MainWindow);
            }
            for (int i = 0; i < objects.size(); i++) {
                StatPresenter->Present(*MainWindow, objects[i]->returnObject());
            }
            StatPresenter->PresentScore(*MainWindow);
        }
        else {
            //std::cout<<"fuck up\n";
            if(isWin == isWinState::Win)
                win();
            if(isWin ==  isWinState::Lose)
                lose();
        }
        present();
    }
}

void Arbitrator::win(){
    finish->returnImageW()->setPosition(MainWindow->getSize().x/2, MainWindow->getSize().y/2);
    MainWindow->draw(*finish->returnImageW());
}

void Arbitrator::lose() {
    finish->returnImageL()->setPosition(MainWindow->getSize().x/2, MainWindow->getSize().y/2);
    MainWindow->draw(*finish->returnImageL());
}

void Arbitrator::present() {
        MainWindow->display();
}

void Arbitrator::exit() {
    MainWindow->close();
    //delete this;
}

Arbitrator::~Arbitrator() {

}
