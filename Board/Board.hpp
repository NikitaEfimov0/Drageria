//
// Created by Никита Ефимов on 19.10.2021.
//

#ifndef MVC_MVP_BOARD_HPP
#define MVC_MVP_BOARD_HPP
#include "Cell.hpp"
#include "BoardGet.hpp"
class Board{
    Cell** arrayofcell;
    int width, height;
public:
    Board();
    Board(int h, int w);
    Board(const Board& other);
    Board(Board&& other);
    Board& operator=(const Board& other);
    Board& operator=(Board&& other);
    ~Board();
    void set_board();
    int return_width();
    int return_height();
    Cell** &return_array();
};


#endif //MVC_MVP_BOARD_HPP
