//
// Created by Никита Ефимов on 08.11.2021.
//

#include "PoisonToolDraw.hpp"
//
// Created by Никита Ефимов on 06.11.2021.
//
PoisonToolDraw::PoisonToolDraw(Cell** &arr, int w, int h, bool Load, int num):array(arr) {
    poisonTool = new PoisonTool(Load, num);
    if(!Load)
        SetRandomPosition(w, h);
    if(poisonTool->return_x()>=w||poisonTool->return_y()>=h)
        throw std::exception();
    array[int(poisonTool->return_y())][int(poisonTool->return_x())].set_Tool(poisonTool);
    texture = new sf::Texture();
    sprite = new sf::Sprite();
    drawable = true;
}

void PoisonToolDraw::set_graphic() {
    texture->loadFromFile(set_path.find("Poison"));
    sprite->setTexture(*texture);
    sprite->setTextureRect(sf::IntRect(1410, 210, 185, 185));
}

bool PoisonToolDraw::check_drawable() {
    if(poisonTool->return_used())
        drawable = false;
    poisonTool->notify();
    return drawable;
}
void PoisonToolDraw::SetRandomPosition(int w, int h) {
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
            poisonTool->set_x((float) randomElementX);
            poisonTool->set_y((float) randomElementY);

            count = 0;
        }
    }
}

void PoisonToolDraw::draw(sf::RenderWindow &window) {
    sprite->setPosition(poisonTool->return_x()*185, poisonTool->return_y()*185);
    window.draw(*sprite);
}