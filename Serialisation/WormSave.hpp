//
// Created by Никита Ефимов on 09.12.2021.
//

#ifndef MVC_MVP_WORMSAVE_HPP
#define MVC_MVP_WORMSAVE_HPP
#include "../Observers/SaveObject.hpp"
class WormSave:public SaveObject{
public:
    WormSave(Object* obj){
        observable = obj;
    }
    void update(int where){
        if(where)
            load();
        else {
            SaveToFile.open("Data/wormHis.json");
            s["x"] = observable->return_x();
            s["y"] = observable->return_y();
            s["health"] = observable->return_health();
            SaveToFile << s;
            SaveToFile.close();
        }
    }
    virtual void load(){
        LoadFromfile.open("Data/wormHis.json");
        if(!is_empty(LoadFromfile)) {

            l = l.parse(LoadFromfile);
            observable->set_x(l["x"]);
            observable->set_y(l["y"]);
            observable->set_health(l["health"]);
            LoadFromfile.close();
        }
    }
};
#endif //MVC_MVP_WORMSAVE_HPP
