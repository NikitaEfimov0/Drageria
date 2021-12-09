//
// Created by Никита Ефимов on 19.10.2021.
//

#ifndef MVC_MVP_BOARDGET_HPP
#define MVC_MVP_BOARDGET_HPP
#include <iostream>

class BoardGet {
    int** arr;
public:
    BoardGet(std::string name, int y, int x);
    int** return_arr();

};


#endif //MVC_MVP_BOARDGET_HPP
