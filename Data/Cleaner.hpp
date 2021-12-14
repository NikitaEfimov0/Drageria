//
// Created by Никита Ефимов on 13.12.2021.
//

#ifndef MVC_MVP_CLEANER_HPP
#define MVC_MVP_CLEANER_HPP
#include <iostream>
#include <fstream>
#include <filesystem>
#include <cstdio>
#include <vector>
namespace fs = std::filesystem;
class Cleaner{
    std::vector<std::string> files;
public:
    int findFile(){
        std::string extension = ".json";
        fs::directory_iterator iterator("Data/");
        for (; iterator != fs::end(iterator); iterator++)
        {
            if (iterator->path().extension() == extension)
            {
                files.push_back(iterator->path().string());
            }
        }
        return files.size();
    }
    void clean(){
        findFile();
        for(int i = 0; i < files.size(); i++){
            remove(files[i].c_str());
        }
    }
};
#endif //MVC_MVP_CLEANER_HPP
