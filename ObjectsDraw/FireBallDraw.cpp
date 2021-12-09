//
// Created by Никита Ефимов on 01.11.2021.
//

#include "FireBallDraw.hpp"
FireBallDraw::FireBallDraw(FireBall *obj, Cell** &arr):array(arr){
    fireball = obj;
    dx = 0;
    dy = 0;
    sprite = new sf::Sprite;
    texture = new sf::Texture;
    CurrentFrame = 0;;
}

void FireBallDraw::draw(sf::RenderWindow &window) {
    move(fireball->return_time());
    //std::cout<<fireball->return_x()<< ' '<<fireball->return_y()<<std::endl;
    sprite->setPosition(fireball->return_x()*185, fireball->return_y()*185);
    window.draw(*sprite);
}

void FireBallDraw::set_graphic() {
    texture->loadFromFile(set_path.find("Fire"));
    sprite->setTexture(*texture);
    //sprite->setTextureRect(sf::IntRect(1250, 125*int(CurrentFrame), 186, 125));
}

void FireBallDraw::move(float time) {

    if(fireball->return_direction() == 0){
        CurrentFrame += 0.005*time;dx = -fireball->return_speed(); dy = 0;//left
        if (CurrentFrame > 4)CurrentFrame-=4;
        sprite->setTextureRect(sf::IntRect(1250, 185*int(CurrentFrame), 185, 185));
    }
    if(fireball->return_direction() == 1){
        CurrentFrame += 0.005*time;dx = fireball->return_speed();dy = 0;//right
        if (CurrentFrame > 4)CurrentFrame-=4;
        sprite->setTextureRect(sf::IntRect(40, 185*int(CurrentFrame), 185, 185));
    }
    if(fireball->return_direction() == 2){
        CurrentFrame += 0.005*time;dy = -fireball->return_speed();dx = 0;//up
        if (CurrentFrame > 4)CurrentFrame-=4;
        sprite->setTextureRect(sf::IntRect(225+185*int(CurrentFrame), 0, 185, 185));
    }
    if(fireball->return_direction() == 3){
        CurrentFrame += 0.005*time;dy = fireball->return_speed();dx = 0;//down
        if (CurrentFrame > 4)CurrentFrame-=4;
        sprite->setTextureRect(sf::IntRect(225+185*int(CurrentFrame), 185, 185, 185));
    }
    fireball->set_x(fireball->return_x()+dx*time);
    collision();
    fireball->set_y(fireball->return_y()+dy*time);
    collision();
    dy = 0;
    dx = 0;
}

void FireBallDraw::collision(){
    for (int i = fireball->return_y(); i < (fireball->return_y() + 1); i++)
        for (int j = fireball->return_x(); j<(fireball->return_x()+1); j++)
        {
            if (array[i][j].return_type() == 1)//если наш квадратик соответствует символу 0 (стена), то проверяем "направление скорости" персонажа:
            {
                if (dy>0)//если мы шли вниз,
                {
                    fireball->set_life(false);
                }
                if (dy<0)
                {
                    fireball->set_life(false);
                }
                if (dx>0)
                {
                    fireball->set_life(false);
                }
                if (dx < 0)
                {
                    fireball->set_life(false);
                }
            }
            if(array[i][j].return_object()!= nullptr){
                //std::cout<<"health before: "<<array[i][j].return_object()->return_health()<<std::endl;
                array[i][j].return_object()->fight(fireball);

                if(array[i][j].return_object()->return_health()<=0){
                    fireball->setKill();
                }
                fireball->set_life(false);
                //std::cout<<"health: "<<array[i][j].return_object()->return_health()<<std::endl;
            }
        }
}

