//
// Created by Никита Ефимов on 19.10.2021.
//

#ifndef MVC_MVP_OBJECTDRAW_HPP
#define MVC_MVP_OBJECTDRAW_HPP
#include "SFML/Graphics.hpp"
#include "../Board/Cell.hpp"
#include "../MainFiles/GetPathToTexture.hpp"
#include "../Observers/Observer.hpp"
#include "../Observers/PresentStat.hpp"

class ObjectDraw {
protected:
    GetPathToTexture set_path;
    sf::Sprite* sprite;
    sf::Texture* texture;
    float CurrentFrame;
    float dx, dy;
    int direction;
    bool drawable;
public:
    virtual ~ObjectDraw(){};
    virtual void draw(sf::RenderWindow& window){};
    virtual void set_graphic(){};
    virtual void get_arrayofcell(Cell** array, int x, int y){};
    virtual  void move(float time){};
    virtual bool check_drawable(){return true;}
    virtual Object* returnObject(){return nullptr;}
    virtual Observer* returnObsFromObj(){return nullptr;};
};


#endif //MVC_MVP_OBJECTDRAW_HPP
