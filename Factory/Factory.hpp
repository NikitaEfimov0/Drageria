//
// Created by Никита Ефимов on 02.12.2021.
//

#ifndef MVC_MVP_FACTORY_HPP
#define MVC_MVP_FACTORY_HPP
#include "../ObjectsDraw/ObjectDraw.hpp"
#include "../Board/Cell.hpp"
class Factory{
protected:
    Cell** array;
    int x, y;
public:
    virtual ~Factory(){};
    virtual ObjectDraw* createObjectDraw() = 0;
};
#endif //MVC_MVP_FACTORY_HPP
