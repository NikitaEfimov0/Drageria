//
// Created by Никита Ефимов on 22.11.2021.
//

#ifndef MVC_MVP_MEDINTERFACE_HPP
#define MVC_MVP_MEDINTERFACE_HPP
class MedInterface{
public:
    virtual void notify() = 0;
    virtual void notify(bool worl) = 0;
    virtual void notify(int wantToPlay) = 0;
};
#endif //MVC_MVP_MEDINTERFACE_HPP
