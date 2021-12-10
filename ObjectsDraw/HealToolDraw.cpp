//
// Created by Никита Ефимов on 06.11.2021.
//

#include "HealToolDraw.hpp"
HealToolDraw::HealToolDraw(Cell** &arr, int w, int h):array(arr) {
    healTool = new HealTool();
    SetRandomPosition(w, h);
    texture = new sf::Texture();
    sprite = new sf::Sprite();
    drawable = true;
}

void HealToolDraw::set_graphic() {
    texture->loadFromFile(set_path.find("Heal"));
    sprite->setTexture(*texture);
    sprite->setTextureRect(sf::IntRect(1130, 210, 185, 185));
}

bool HealToolDraw::check_drawable() {
    if(healTool->return_used())
        drawable = false;
    healTool->notify();
    return drawable;
}

void HealToolDraw::SetRandomPosition(int w, int h) {
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
            healTool->set_x((float) randomElementX);
            healTool->set_y((float) randomElementY);
            array[randomElementY][randomElementX].set_Tool(healTool);
            count = 0;
        }
    }
}

void HealToolDraw::draw(sf::RenderWindow &window) {
    sprite->setPosition(healTool->return_x()*185, healTool->return_y()*185);
    window.draw(*sprite);
}