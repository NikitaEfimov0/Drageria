//
// Created by Никита Ефимов on 08.11.2021.
//

#ifndef MVC_MVP_OBSERVER_HPP
#define MVC_MVP_OBSERVER_HPP
#include <iostream>
#include <fstream>
#include "Object.hpp"

class Observer{
    std::ofstream LogFile;
protected:
    Object* observable;
public:
    Observer(){
        LogFile.open("./logging/log.txt");
    }
    Observer(Object* publisher):observable(publisher){
        LogFile.open("./logging/log.txt");
    }

    friend std::ostream& operator<< (std::ostream &out, const Observer& observer){
        out << "x: "<<observer.observable->return_x()<<' '<<"y: "<<observer.observable->return_y()<<' '<<"health: "<<observer.observable->return_health()<<'\n';
        return out;
    }

    friend std::ofstream& operator<<(std::ofstream& out, const Observer& observer){
        out << "x: "<<observer.observable->return_x()<<' ';
        out<< "y: "<<observer.observable->return_y()<<' ';
        out<<"health: "<<observer.observable->return_health()<<std::endl;
        return out;
    }

    void WriteToConsole(){
        std::cout<<*this;
    }

    void WriteToFile(){
        LogFile <<*this;
    }

    void WriteToConsoleAndFile(){
        WriteToFile();
        WriteToConsole();
    }
    virtual void update(){};
    void update(int where){
        if(where == 0){
            WriteToConsole();
        }
        if(where == 1){
            WriteToFile();
        }
        if(where == 2){
            WriteToConsoleAndFile();
        }

    }
    ~Observer(){
        observable = nullptr;
        LogFile.close();
    }
};


#endif //MVC_MVP_OBSERVER_HPP
