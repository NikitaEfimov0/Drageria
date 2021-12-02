//
// Created by Никита Ефимов on 19.10.2021.
//

#include "BoardGet.hpp"
#include <fstream>
#include <iostream>
using namespace std;
BoardGet::BoardGet(std::string name, int y, int x) {
    ifstream F;
    F.open(name, ios::in);
    arr = new int*[y];
    for(int i = 0; i < y; i++){
        arr[i] = new int[x];
        for(int j = 0; j < x; j++){
            F>>arr[i][j];
        }
    }
}
int** BoardGet::return_arr() {
    return arr;
}