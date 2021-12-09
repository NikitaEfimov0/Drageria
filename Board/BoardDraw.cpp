//
// Created by Никита Ефимов on 19.10.2021.
//

#include "BoardDraw.hpp"
#include <iostream>
using namespace sf;
BoardDraw::BoardDraw(){
    arr = new Cell*[0];
    h = 0; w  = 0;
    texture = new Texture();
    sprite = new Sprite();
}

void BoardDraw::set_graphic() {
    texture->loadFromFile(set_path.find("Board"));
    sprite->setTexture(*texture);
}

void BoardDraw::get_arrayofcell(Cell **array, int x, int y) {
    h = y; w = x;
    arr = array;
}

void BoardDraw::draw(sf::RenderWindow& window) {
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(arr[i][j].return_type() == 2){
                sprite->setTextureRect(IntRect(415, 280, 185, 185));
            }
            else if (arr[i][j].return_type() == 3){
                sprite->setTextureRect(IntRect(840, 280, 185, 185));
            }
            else if(arr[i][j].return_type() == 1){
                sprite->setTextureRect(IntRect(840, 700, 185, 185));
            }
            else{
                sprite->setTextureRect(IntRect(130, 67, 185, 185));
            }
            sprite->setPosition(j*185, i*185);
            window.draw(*sprite);
        }
    }
}