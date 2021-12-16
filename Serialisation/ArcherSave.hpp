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
    void update(int where){
        if(where)
            load();
        else {
            s = tmpLoad();
            SaveToFile.open("Data/archerHis.json");
            s[std::to_string(observable->returnNumber())]["x"] = observable->return_x();
            s[std::to_string(observable->returnNumber())]["y"] = observable->return_y();
            s[std::to_string(observable->returnNumber())]["health"] = observable->return_health();
            SaveToFile << s;
            SaveToFile.close();
        }
    }
    virtual void load(){
        LoadFromfile.open("Data/archerHis.json");
        if(!is_empty(LoadFromfile)) {
            l = l.parse(LoadFromfile);
            observable->set_x(l[std::to_string(observable->returnNumber())]["x"]);
            observable->set_y(l[std::to_string(observable->returnNumber())]["y"]);
            observable->set_health(l[std::to_string(observable->returnNumber())]["health"]);
            LoadFromfile.close();
        }

    }
    virtual json tmpLoad(){
        LoadFromfile.open("Data/archerHis.json");
        if(!is_empty(LoadFromfile)){
            tmp = json::parse(LoadFromfile);
        }
        else
            tmp = s;
        LoadFromfile.close();
        return tmp;
    }
};
#endif //MVC_MVP_ARCHERSAVE_HPP
