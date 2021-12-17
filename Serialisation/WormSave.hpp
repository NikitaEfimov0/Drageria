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
            s = tmpLoad();
            SaveToFile.open("Data/wormHis.json");
            s[std::to_string(observable->returnNumber())]["x"] = observable->return_x();
            s[std::to_string(observable->returnNumber())]["y"] = observable->return_y();
            s[std::to_string(observable->returnNumber())]["health"] = observable->return_health();
            SaveToFile << s;
            SaveToFile.close();
        }
    }
    virtual void load(){
        LoadFromfile.open("Data/wormHis.json");
        if(!is_empty(LoadFromfile)) {
            l = l.parse(LoadFromfile);
            //try {
            observable->set_x(l[std::to_string(observable->returnNumber())]["x"]);
            observable->set_y(l[std::to_string(observable->returnNumber())]["y"]);
            observable->set_health(l[std::to_string(observable->returnNumber())]["health"]);
//            }catch(json::exception& ex){
//                throw std::runtime_error("ALARM!");
//            }
            LoadFromfile.close();
        }
        else
            throw std::exception();
    }
    virtual json tmpLoad(){
        LoadFromfile.open("Data/wormHis.json");
        if(!is_empty(LoadFromfile)){
            try {
                tmp = json::parse(LoadFromfile);
            }catch(json::parse_error& ex){
                tmp.clear();
            }
        }
        else
            tmp = s;
        LoadFromfile.close();
        return tmp;
    }
};
#endif //MVC_MVP_WORMSAVE_HPP
