//
// Created by Никита Ефимов on 29.10.2021.
//

#include "GetPathToTexture.hpp"
std::string GetPathToTexture::find(const std::string& name){
    std::ifstream file;
    file.open(fileMain);
    while(!file.eof()){
        std::string tmp;
        getline(file, tmp);
        int where = tmp.find(name, 0);
        if(where!=-1){
            int start = 0;
            for(int i = 0; i < tmp.length();i++) {
                while (tmp[i] != '.' && start == 0){
                    i++;
                }
                start = 1;
                path.push_back(tmp[i]);
            }
            return path;
        }
    }
    return nullptr;
}