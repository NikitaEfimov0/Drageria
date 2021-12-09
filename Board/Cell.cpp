//
// Created by Никита Ефимов on 19.10.2021.
//

#include "Cell.hpp"
Cell::Cell(){
    object = nullptr;
    tool = nullptr;
    type = 0;
}
void Cell::set_type(int i){
    type = i;
}
int Cell::return_type(){
    return type;
}
Object* Cell::return_object() {
    return object;
}

void Cell::set_object(Object* new_object) {
    object = new_object;
}

void Cell::delete_object() {
    object = nullptr;
}

void Cell::set_Tool(Tool* new_object) {
    tool = new_object;
}

void Cell::delete_tool() {
    tool = nullptr;
}

Tool* Cell::return_tool() {
    return tool;
}