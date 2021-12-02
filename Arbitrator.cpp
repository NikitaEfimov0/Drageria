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
    isWin = false;
    mediator = med;
}

void Arbitrator::start_working(int a, int w, int d) {
    MainBoard->set_board();
    objects.push_back(new HeroDraw(MainBoard->return_array(), MainBoard->return_height(), MainBoard->return_width()));
    StatPresenter = new PresentStat(objects[1]->returnObsFromObj());
    WormFactory wf(MainBoard->return_array(), MainBoard->return_width(), MainBoard->return_height());
    ArcherFactory af(MainBoard->return_array(), MainBoard->return_width(), MainBoard->return_height());
    DragonFactory df(MainBoard->return_array(), MainBoard->return_width(), MainBoard->return_height());
    for(int i = 0; i < a; i++){
        objects.push_back(af.createObjectDraw());
    }
    for(int i = 0; i < w; i++){
        objects.push_back(wf.createObjectDraw());
    }
    for(int i = 0; i < d; i++){
        objects.push_back(df.createObjectDraw());
    }

//    objects.push_back(new ArcherDraw((MainBoard->return_array()), MainBoard->return_width(), MainBoard->return_height()));
//    objects.push_back(new WormDraw((MainBoard->return_array()), MainBoard->return_width(), MainBoard->return_height()));
//    objects.push_back(new DragonDraw((MainBoard->return_array()), MainBoard->return_width(), MainBoard->return_height()));
    objects.push_back(new HealToolDraw((MainBoard->return_array()), MainBoard->return_width(), MainBoard->return_height()));
    objects.push_back(new PoisonToolDraw((MainBoard->return_array()), MainBoard->return_width(), MainBoard->return_height()));
    objects.push_back(new SuperHealToolDraw((MainBoard->return_array()), MainBoard->return_width(), MainBoard->return_height()));
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
                if (keys.checkExit())
                    MainWindow->close();
//                if(Keyboard::isKeyPressed(sf::Keyboard::P) && isFinish) {
//                    mediator->notify(1);
//                }
            }
        }

        mediator->notify();
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
            if(isWin)
                win();
            else
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
    delete MainBoard;
    objects.clear();
    delete MainWindow;

}
