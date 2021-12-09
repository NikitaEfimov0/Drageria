//
// Created by Никита Ефимов on 19.10.2021.
//

#ifndef MVC_MVP_CELL_HPP
#define MVC_MVP_CELL_HPP
#include "../Objects/Object.hpp"
#include "../Objects/Tool.hpp"
class Cell {
    int type;
    Object* object;
    Tool* tool;
public:
    Cell();
    void set_type(int i);
    int return_type();
    Object* return_object();
    Tool* return_tool();
    void delete_object();
    void set_object(Object* new_object);
    void delete_tool();
    void set_Tool(Tool* new_object);
};


#endif //MVC_MVP_CELL_HPP
