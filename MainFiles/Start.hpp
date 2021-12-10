//
// Created by Никита Ефимов on 09.12.2021.
//

#ifndef MVC_MVP_START_HPP
#define MVC_MVP_START_HPP
#include "../Menu/Menu.hpp"
class Start{
    Menu* menu;
public:
    Start(){
        menu = new Menu();
    }

};
#endif //MVC_MVP_START_HPP
