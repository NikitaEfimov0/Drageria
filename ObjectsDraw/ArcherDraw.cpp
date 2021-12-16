//
// Created by Никита Ефимов on 04.11.2021.
//
#include "ArcherDraw.hpp"

ArcherDraw::ArcherDraw(Cell **&array, int w, int h, bool Load, int num):arr(array) {
    archer = new Archer(Load, num);
    if(!Load)
        SetRandomPosition(array, w, h);
    dx = 0; dy = 0;
    direction = 1;
    CurrentFrame = 0;
    texture = new sf::Texture();
    sprite = new sf::Sprite();
    drawable = true;
}

void ArcherDraw::set_graphic() {
    texture->loadFromFile(set_path.find("Archer"));
    sprite->setTexture(*texture);
    sprite->setTextureRect(sf::IntRect(0, 0, 185, 185));
}

void ArcherDraw::draw(sf::RenderWindow &window) {
    sprite->setPosition(archer->return_x()*185, archer->return_y()*185);
    //std::cout<<"x: "<<archer->return_x()<<' '<<"y: "<<archer->return_y()<<std::endl;
    window.draw(*sprite);
}

void ArcherDraw::SetRandomPosition(Cell** array, int w, int h) {
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
            archer->set_x((float) randomElementX);
            archer->set_y((float) randomElementY);
            array[randomElementY][randomElementX].set_object(archer);
            count = 0;
        }
    }
}

bool ArcherDraw::check_drawable() {
    if(archer->return_health() <= 0){
        drawable = false;
        arr[(int)archer->return_y()][(int)archer->return_x()].delete_object();
    }
    return drawable;
}

void ArcherDraw::move(float time){

    if(direction == 1){
        CurrentFrame += 0.005*time;dx = archer->return_speed();
        if (CurrentFrame > 8)CurrentFrame-=8;
        sprite->setTextureRect(sf::IntRect(int(CurrentFrame)*185, 0, 185, 185));
    }
    if(direction == 2){
        CurrentFrame += 0.005*time;dx = archer->return_speed()*(-1);
        if (CurrentFrame > 8)CurrentFrame-=8;
        sprite->setTextureRect(sf::IntRect(int(CurrentFrame)*185, 200, 185, 185));
    }
    arr[(int)(archer->return_y())][(int)(archer->return_x())].delete_object();
    archer->set_x(archer->return_x()+dx*time);
    collision();
    arr[(int)(archer->return_y())][(int)(archer->return_x())].set_object(archer);
    archer->notify();
    dx = 0;
}

void ArcherDraw::collision() {
    for (int i = archer->return_y(); i < (archer->return_y() + 1); i++)
        for (int j = archer->return_x(); j<(archer->return_x() + 1); j++)
        {
            if ( arr[i][j].return_type()==1)
            {
                if (dx>0){ archer->set_x(float(j) -1); direction = 2; }
                if (dx<0){ archer->set_x(float(j)+1); direction = 1; }
            }
        }
}

