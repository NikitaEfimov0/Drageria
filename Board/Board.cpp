//
// Created by Никита Ефимов on 19.10.2021.
//
#include <iostream>
#include "Board.hpp"
Board::Board() {
    width = 0;
    height = 0;
    arrayofcell = new Cell*[0];
}

Board::Board(int h, int w){
    width = w;
    height = h;
    arrayofcell = new Cell*[h];
    for(int i = 0; i < height; i++)
        arrayofcell[i] = new Cell[w];
}

Board::Board(const Board& other){
    width = other.width;
    height = other.height;
    for(int i = 0; i < height; i++)
        for(int j = 0; j < width;j++)
            arrayofcell[i][j] = other.arrayofcell[i][j];
}

Board& Board:: operator=(const Board& other){
    if(this!=&other){
        width = other.width;
        height = other.height;
        for(int i = 0; i < height; i++)
            for(int j = 0; j < width;j++)
                arrayofcell[i][j] = other.arrayofcell[i][j];
    }
    return *this;
}

Board::Board(Board&& other){
    std::swap(height, other.height);
    std::swap(width, other.width);
    std::swap(arrayofcell, other.arrayofcell);
    for(int i = 0; i < height; i++)
        delete[] other.arrayofcell[i];
    delete[]other.arrayofcell;
}

Board& Board::operator=(Board&& other){
    if(this!=&other){
        std::swap(height, other.height);
        std::swap(width, other.width);
        std::swap(arrayofcell, other.arrayofcell);
        for(int i = 0; i < height; i++)
            delete[] other.arrayofcell[i];
        delete[]other.arrayofcell;
    }
    return *this;
}

void Board::set_board() {
    BoardGet* get = new BoardGet("./levels/lvl1.txt", height, width);
    for(int i = 0; i < height; i++)
        for(int j = 0; j < width;j++){
            arrayofcell[i][j].set_type(get->return_arr()[i][j]);

        }

}

Board::~Board() {
    for(int i = 0; i < height; i++){
        delete[]arrayofcell[i];
    }
    delete[]arrayofcell;
    height = 0;
    width = 0;
}
int Board::return_height() {
    return height;
}
int Board::return_width() {
    return width;
}

Cell** &Board::return_array() {
    return arrayofcell;
}
