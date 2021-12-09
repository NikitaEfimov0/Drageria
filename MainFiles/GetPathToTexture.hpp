//
// Created by Никита Ефимов on 29.10.2021.
//

#ifndef MVC_MVP_GETPATHTOTEXTURE_HPP
#define MVC_MVP_GETPATHTOTEXTURE_HPP
#include<iostream>
#include <fstream>
class GetPathToTexture {
    std::string fileMain;
    std::string path;
public:
    GetPathToTexture(){
        fileMain = "config.txt";
    }
    std::string find(const std::string& name);
};


#endif //MVC_MVP_GETPATHTOTEXTURE_HPP
