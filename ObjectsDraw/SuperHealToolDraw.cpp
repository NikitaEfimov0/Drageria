//
// Created by Никита Ефимов on 08.11.2021.
//

#include "SuperHealToolDraw.hpp"

SuperHealToolDraw::SuperHealToolDraw(Cell** &arr, int w, int h, bool Load, int num):array(arr) {
    superHealTool = new SuperHealTool(Load, num);
    if(!Load)
        SetRandomPosition(w, h);
    if(superHealTool->return_x()>=w||superHealTool->return_y()>=h)
        throw std::exception();
    array[int(superHealTool->return_y())][int(superHealTool->return_x())].set_Tool(superHealTool);
    texture = new sf::Texture();
    sprite = new sf::Sprite();
    drawable = true;
}

void SuperHealToolDraw::set_graphic() {
    texture->loadFromFile(set_path.find("SuperHeal"));
    sprite->setTexture(*texture);
    sprite->setTextureRect(sf::IntRect(1670, 210, 185, 185));
}

bool SuperHealToolDraw::check_drawable() {
    if(superHealTool->return_used())
        drawable = false;
    superHealTool->notify();
    return drawable;
}

void SuperHealToolDraw::SetRandomPosition(int w, int h) {
    int randomElementX = 0;//случайный элемент по горизонтали
    int randomElementY = 0;//случ эл-т по вертикали
    int count = 1;
    srand(time(0));
    while(count!=0){

        randomElementX = 1 + rand() % (w - 1);
        randomElementY = 1 + rand() % (h - 1);
        //std::cout<<"healtool x: "<<randomElementX<<' '<<"healtool y: "<<randomElementY<<' '<<"type: "<<array[randomElementY][randomElementX].return_type() <<std::endl;
        if(array[randomElementY][randomElementX].return_type()==0 && array[randomElementY][randomElementX].return_object()== nullptr && array[randomElementY][randomElementX].return_tool()== nullptr){
            //std::cout<<"mazafacka"<<std::endl;
            superHealTool->set_x((float) randomElementX);
            superHealTool->set_y((float) randomElementY);


            count = 0;
        }
    }
}

void SuperHealToolDraw::draw(sf::RenderWindow &window) {
    sprite->setPosition(superHealTool->return_x()*185, superHealTool->return_y()*185);
    window.draw(*sprite);
}