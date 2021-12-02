//
// Created by Никита Ефимов on 06.11.2021.
//

#ifndef MVC_MVP_TOOL_HPP
#define MVC_MVP_TOOL_HPP
#include "Object.hpp"

class Tool :public Object{
public:
    virtual void usage(Object* hero){}
    virtual bool return_used(){return false;}
};


#endif //MVC_MVP_TOOL_HPP
