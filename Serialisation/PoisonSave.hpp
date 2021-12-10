//
// Created by Никита Ефимов on 10.12.2021.
//

#ifndef MVC_MVP_POISONSAVE_HPP
#define MVC_MVP_POISONSAVE_HPP
#include "../Observers/SaveObject.hpp"
class PoisonSave:public SaveObject{
public:
    PoisonSave(Object* obj){
        observable = obj;
    }
    void update(){
        SaveToFile.open("Data/PoisonHis.json");
        s["x"] = observable->return_x();
        s["y"] = observable->return_y();
        s["used"] = observable->return_used();
        SaveToFile<<s;
        SaveToFile.close();
    }
    virtual void load(){
        if(!is_empty(LoadFromfile)) {
            LoadFromfile.open("Data/PoisonHis.json");
            l = l.parse(LoadFromfile);
            observable->set_x(l["x"]);
            observable->set_y(l["y"]);
            observable->set_used(l["used"]);
            LoadFromfile.close();
        }
    }
};
#endif //MVC_MVP_POISONSAVE_HPP
