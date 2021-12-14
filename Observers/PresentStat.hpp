//
// Created by Никита Ефимов on 08.11.2021.
//

#ifndef MVC_MVP_PRESENTSTAT_HPP
#define MVC_MVP_PRESENTSTAT_HPP
#include "../Objects/Object.hpp"
#include "SFML/Graphics.hpp"
#include "../MainFiles/GetPathToTexture.hpp"
#include "HeroStatistic.hpp"
#include <iostream>
#include <sstream>
class PresentStat {
    HeroStatistic* stat;
    GetPathToTexture set_path;
    sf::Font font;
    sf::Text* text;
    sf::Text* scText;
public:
    PresentStat(Observer* s):stat(dynamic_cast<HeroStatistic*>(s)){
        font.loadFromFile(set_path.find("Font"));
        text = new sf::Text("", font, 50);
        scText = new sf::Text("", font, 60);
        text->setFillColor(sf::Color::Red);
        text->setStyle(sf::Text::Bold);
        scText->setFillColor(sf::Color::Red);
        scText->setStyle(sf::Text::Italic);
    }
    void Present(sf::RenderWindow& window, Object* object) {
        std::ostringstream life;
        if(object!= nullptr){
            life << object->return_health();
            text->setString("hp: " + life.str());
            text->setPosition(object->return_x()*185, (object->return_y()*185) - 100);
            window.draw(*text);
        }
    }
    HeroStatistic* returnScore(){return stat;}
//    void setScore(int i){
//        score += i;
//    }
    void PresentScore(sf::RenderWindow& window){
        std::ostringstream sc;
        sc<<stat->returnCurrentScore();
        scText->setString("Score: "+sc.str());
        scText->setPosition(0, 0);
        window.draw(*scText);
    }
//    ~PresentStat(){
//        delete stat;
//        delete text;
//        delete scText;
//        delete stat;
//    }
};


#endif //MVC_MVP_PRESENTSTAT_HPP
