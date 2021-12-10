//
// Created by Никита Ефимов on 09.12.2021.
//

#ifndef MVC_MVP_ARCHERSAVE_HPP
#define MVC_MVP_ARCHERSAVE_HPP
#include "../Observers/SaveObject.hpp"
class ArcherSave:public SaveObject{
public:
    ArcherSave(Object* obj){
        observable = obj;
    }
    void update(){
        SaveToFile.open("Data/archerHis.json");
        s["x"] = observable->return_x();
        s["y"] = observable->return_y();
        s["health"] = observable->return_health();
        SaveToFile<<s;
        SaveToFile.close();
    }
    virtual void load(){
        if(!is_empty(LoadFromfile)) {
            LoadFromfile.open("Data/archerHis.json");
            l = l.parse(LoadFromfile);
            observable->set_x(l["x"]);
            observable->set_y(l["y"]);
            observable->set_health(l["health"]);
            LoadFromfile.close();
        }
    }
};
#endif //MVC_MVP_ARCHERSAVE_HPP
