

#include "DragonDraw.hpp"
//
// Created by Никита Ефимов on 06.11.2021.
//

DragonDraw::DragonDraw(Cell **&array, int w, int h, bool Load, int num):arr(array) {
    dragon = new Dragon(Load, num);

    if(!Load)
        SetRandomPosition(array, w, h);
    else if(dragon->return_x()<w && dragon->return_y()<h && (dragon->return_x()>0 && dragon->return_y()>0))
        arr[(int)(dragon->return_y())][(int)(dragon->return_x())].set_object(dragon);
    else
        throw std::exception();
    //SetRandomPosition(array, w, h);
    dx = 0; dy = 0;
    direction = 1;
    CurrentFrame = 0;
    texture = new sf::Texture();
    sprite = new sf::Sprite();
    drawable = true;
}

void DragonDraw::set_graphic() {
    texture->loadFromFile(set_path.find("Dragon"));
    sprite->setTexture(*texture);
    sprite->setTextureRect(sf::IntRect(0, 0, 185, 110));
}

void DragonDraw::draw(sf::RenderWindow &window) {
    sprite->setPosition(dragon->return_x()*185, dragon->return_y()*185);
    window.draw(*sprite);
}

bool DragonDraw::check_drawable() {
    if(dragon->return_health() <= 0){
        drawable = false;
        arr[(int)dragon->return_y()][(int)dragon->return_x()].delete_object();
    }
    return drawable;
}

void DragonDraw::SetRandomPosition(Cell** array, int w, int h) {
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
            dragon->set_x((float) randomElementX);
            dragon->set_y((float) randomElementY);
            array[randomElementY][randomElementX].set_object(dragon);
            count = 0;
        }
    }
}

void DragonDraw::move(float time){

    if(direction == 1){
        CurrentFrame += 0.005*time;dx = dragon->return_speed();
        if (CurrentFrame > 8)CurrentFrame-=8;
        sprite->setTextureRect(sf::IntRect(int(CurrentFrame)*185, 150, 185, 185));
    }
    if(direction == 2){
        CurrentFrame += 0.005*time;dx = dragon->return_speed()*(-1);
        if (CurrentFrame > 8)CurrentFrame-=8;
        sprite->setTextureRect(sf::IntRect(int(CurrentFrame)*185, 460, 185, 185));
    }
    arr[(int)(dragon->return_y())][(int)(dragon->return_x())].delete_object();
    dragon->set_x(dragon->return_x()+dx*time);
    collision();
    arr[(int)(dragon->return_y())][(int)(dragon->return_x())].set_object(dragon);
    dragon->notify();
    dx = 0;
}

void DragonDraw::collision() {
    for (int i = dragon->return_y(); i < (dragon->return_y() + 1); i++)
        for (int j = dragon->return_x(); j<(dragon->return_x() + 1); j++)
        {
            if ( arr[i][j].return_type()==1)
            {
                if (dx>0){ dragon->set_x(float(j) -1); direction = 2; }
                if (dx<0){ dragon->set_x(float(j)+1); direction = 1; }
            }
        }
}

