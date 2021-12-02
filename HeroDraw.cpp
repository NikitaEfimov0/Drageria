//
// Created by Никита Ефимов on 21.10.2021.
//

#include "HeroDraw.hpp"
HeroDraw::HeroDraw(Cell **&arr, int w, int h):array(arr){
    for(int i = 0;i < h; i++ )
        for(int j = 0; j < w; j++)
            if(arr[i][j].return_type() == 2) {
                hero = new Hero(j, i);
            }
    dx = 0; dy = 0;
    CurrentFrame = 0;
    texture = new sf::Texture();
    sprite = new sf::Sprite();
    if_shooted = false;
    saveDirect = 3;
    drawable = true;
    keyReader = new KeyReader();
}

void HeroDraw::set_graphic() {
    texture->loadFromFile(set_path.find("Hero"));
    sprite->setTexture(*texture);
    sprite->setTextureRect(sf::IntRect(0, 0, 140, 175));
}

void HeroDraw::draw(sf::RenderWindow &window) {
    sprite->setPosition(hero->return_x()*185, hero->return_y()*185);
    window.draw(*sprite);
    if(!balls.empty()){
        for(int i = 0; i < balls.size(); i++){
            balls[i]->draw(window);
            check();
            if(!balls[i]->return_fireball()->return_life())
                balls.erase(balls.begin()+i);
        }
    }
}
bool HeroDraw::check_drawable() {
    if(hero->return_health() <= 0){
        drawable = false;
    }
    return drawable;
}
void HeroDraw::move(float time) {
        if(keyReader->checkL()){
            CurrentFrame += 0.005*time;dx = -hero->return_speed(); dy = 0; saveDirect = 0;//left
            if (CurrentFrame > 8)CurrentFrame-=8;
            sprite->setTextureRect(sf::IntRect(186*int(CurrentFrame), 195, 186, 105));
        }
        if(keyReader->checkR()){
            CurrentFrame += 0.005*time;dx = hero->return_speed();dy = 0; saveDirect = 1;//right
            if (CurrentFrame > 8)CurrentFrame-=8;
            sprite->setTextureRect(sf::IntRect(182*int(CurrentFrame), 300, 182, 130));
        }
        if(keyReader->checkF()){
            CurrentFrame += 0.005*time;dy = -hero->return_speed();dx = 0;saveDirect = 2;//up
            if (CurrentFrame > 8)CurrentFrame-=8;
            sprite->setTextureRect(sf::IntRect(135*int(CurrentFrame), 450, 135, 135));
        }
        if(keyReader->checkB()){
            CurrentFrame += 0.005*time;dy = hero->return_speed();dx = 0;saveDirect = 3;//down
            if (CurrentFrame > 8)CurrentFrame-=8;
            sprite->setTextureRect(sf::IntRect(int(CurrentFrame)*150, 0, 150, 175));
        }
        if(keyReader->checkSh()){
            if(!if_shooted){
                FireBall* fireball = new FireBall(hero->return_x(), hero->return_y(), saveDirect, time);
                balls.push_back(new FireBallDraw(fireball, array));
                balls[balls.size()-1]->set_graphic();
                if_shooted = true;
            }

        }
        else{
            if_shooted = false;
        }

        hero->set_x(hero->return_x()+dx*time);
        collision();
        hero->set_y(hero->return_y()+dy*time);
        collision();
        hero->notify();
        dy = 0;
        dx = 0;
    }
void HeroDraw::check(){
    for(int i = 0; i < balls.size();i++){
        if(balls[i]->return_fireball()->returnKill()){
            hero->setKills();
            continue;
        }
        else
            continue;
    }
}

void HeroDraw::collision(){
    for (int i = hero->return_y(); i < (hero->return_y() + 1); i++)
        for (int j = hero->return_x(); j<(hero->return_x()+1); j++)
        {
            if (array[i][j].return_type() == 1)//если наш квадратик соответствует символу 0 (стена), то проверяем "направление скорости" персонажа:
            {
                if (dy>0)//если мы шли вниз,
                {
                    hero->set_y(float(i)-1);
                    dy = 0;
                }
                if (dy<0)
                {
                    hero->set_y(float(i)+1);
                    dy = 0;//аналогично с ходьбой вверх. dy<0, значит мы идем вверх (вспоминаем координаты паинта)
                }
                if (dx>0)
                {
                    hero->set_x(float(j)-1);
                    dx = 0;//если идем вправо, то координата Х равна стена (символ 0) минус ширина персонажа
                }
                if (dx < 0)
                {
                    hero->set_x(float(j)+1);
                    dx = 0;//аналогично идем влево
                }
            }
            if(!if_shooted)
                if(array[i][j].return_object()!= nullptr){
                    //std::cout<<"health before: "<<array[i][j].return_object()->return_health()<<std::endl;
                    array[i][j].return_object()->fight(hero);
                    if(array[i][j].return_object()->return_health()<=0)
                        hero->setKills();
                    //std::cout<<"health: "<<array[i][j].return_object()->return_health()<<std::endl;
                    if_shooted = true;

                }
            if(array[i][j].return_tool()!= nullptr){
                //std::cout<<"health before: "<<hero->return_health()<<std::endl;
                array[i][j].return_tool()->usage(hero);
                array[i][j].delete_tool();
                //std::cout<<"health: "<<hero->return_health()<<std::endl;
            }
//            if(i ==  && j == int(hero->return_y())){
//                hero->setF();
//            }
    }
}
Observer* HeroDraw::returnObsFromObj() {
    return hero->returnConcrObs();
}