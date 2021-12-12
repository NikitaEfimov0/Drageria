//
// Created by Никита Ефимов on 10.12.2021.
//

#ifndef MVC_MVP_HEALSAVE_HPP
#define MVC_MVP_HEALSAVE_HPP
#include "../Observers/SaveObject.hpp"
class HealSave:public SaveObject{
public:
    HealSave(Object* obj){
        observable = obj;
    }
    void update(int where){
        if(where)
            load();
        else {
            SaveToFile.open("Data/HealHis.json");
            s["x"] = observable->return_x();
            s["y"] = observable->return_y();
            s["used"] = observable->return_used();
            SaveToFile << s;
            SaveToFile.close();
        }
    }
    virtual void load(){
        LoadFromfile.open("Data/HealHis.json");
        if(!is_empty(LoadFromfile)) {

            l = l.parse(LoadFromfile);
            observable->set_x(l["x"]);
            observable->set_y(l["y"]);
            observable->set_used(l["used"]);
            LoadFromfile.close();
        }
    }
};
#endif //MVC_MVP_HEALSAVE_HPP
