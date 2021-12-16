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
    void update(int where){
        if(where)
            load();
        else {
            s = tmpLoad();
            SaveToFile.open("Data/PoisonHis.json");
            s[std::to_string(observable->returnNumber())]["x"] = observable->return_x();
            s[std::to_string(observable->returnNumber())]["y"] = observable->return_y();
            s[std::to_string(observable->returnNumber())]["used"] = observable->return_used();
            SaveToFile << s;
            SaveToFile.close();
        }
    }
    virtual void load(){
        LoadFromfile.open("Data/PoisonHis.json");
        if(!is_empty(LoadFromfile)) {
            l = l.parse(LoadFromfile);
            observable->set_x(l[std::to_string(observable->returnNumber())]["x"]);
            observable->set_y(l[std::to_string(observable->returnNumber())]["y"]);
            observable->set_used(l[std::to_string(observable->returnNumber())]["used"]);
            LoadFromfile.close();
        }
    }
    virtual json tmpLoad(){
        LoadFromfile.open("Data/PoisonHis.json");
        if(!is_empty(LoadFromfile)){
            tmp = json::parse(LoadFromfile);
        }
        else
            tmp = s;
        LoadFromfile.close();
        return tmp;
    }
};
#endif //MVC_MVP_POISONSAVE_HPP
