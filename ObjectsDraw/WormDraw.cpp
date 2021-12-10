#include "WormDraw.hpp"
//
// Created by Никита Ефимов on 04.11.2021.
//

WormDraw::WormDraw(Cell **&array, int w, int h):arr(array) {
    worm = new Worm();
    SetRandomPosition(array, w, h);
    dx = 0; dy = 0;
    direction = 1;
    CurrentFrame = 0;
    texture = new sf::Texture();
    sprite = new sf::Sprite();
    drawable = true;
}

void WormDraw::set_graphic() {
    texture->loadFromFile(set_path.find("Worm"));
    sprite->setTexture(*texture);
    sprite->setTextureRect(sf::IntRect(0, 0, 185, 185));
}

void WormDraw::draw(sf::RenderWindow &window) {
    sprite->setPosition(worm->return_x()*185, worm->return_y()*185);
    window.draw(*sprite);
}

bool WormDraw::check_drawable() {
    if(worm->return_health() <= 0){
        drawable = false;
        arr[(int)worm->return_y()][(int)worm->return_x()].delete_object();
    }
    return drawable;
}

void WormDraw::move(float time){

    if(direction == 1){
        CurrentFrame += 0.005*time;dx = worm->return_speed();
        if (CurrentFrame > 9)CurrentFrame-=9;
        sprite->setTextureRect(sf::IntRect(int(CurrentFrame)*185, 0, 185, 185));
    }
    if(direction == 2){
        CurrentFrame += 0.005*time;dx = worm->return_speed()*(-1);
        if (CurrentFrame > 9)CurrentFrame-=9;
        sprite->setTextureRect(sf::IntRect(int(CurrentFrame)*185, 185, 185, 185));
    }
    arr[(int)(worm->return_y())][(int)(worm->return_x())].delete_object();
    worm->set_x(worm->return_x()+dx*time);
    collision();
    arr[(int)(worm->return_y())][(int)(worm->return_x())].set_object(worm);
    worm->notify();
    dx = 0;
}

void WormDraw::SetRandomPosition(Cell** array, int w, int h) {
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
            worm->set_x((float) randomElementX);
            worm->set_y((float) randomElementY);
            array[randomElementY][randomElementX].set_object(worm);
            count = 0;
        }
    }
}

void WormDraw::collision() {
    for (int i = worm->return_y(); i < (worm->return_y() + 1); i++)
        for (int j = worm->return_x(); j<(worm->return_x() + 1); j++)
        {
            if ( arr[i][j].return_type()==1)
            {
                if (dx>0){ worm->set_x(float(j) -1); direction = 2; }
                if (dx<0){ worm->set_x(float(j)+1); direction = 1; }
            }
        }
}

