//
// Created by Никита Ефимов on 09.12.2021.
//

#ifndef MVC_MVP_SAVEOBJECT_HPP
#define MVC_MVP_SAVEOBJECT_HPP
#include "../Objects/Object.hpp"
#include "Observer.hpp"
#include "nlohmann/json.hpp"
#include <fstream>
#include <iostream>
using json = nlohmann::json;
class SaveObject:public Observer{
protected:
    json s;
    json l;
    json tmp;
    std::ifstream LoadFromfile;
    std::ofstream SaveToFile;
public:
    SaveObject(Object* obj){
        observable = obj;
    }
    SaveObject(){
    }
    bool is_empty(std::ifstream& pFile)
    {
        return pFile.peek() == std::ifstream::traits_type::eof();
    }
    //void update(){std::cout<<2;};
    virtual void load(){};
    virtual json tmpLoad(){return nullptr;}
};
#endif //MVC_MVP_SAVEOBJECT_HPP
