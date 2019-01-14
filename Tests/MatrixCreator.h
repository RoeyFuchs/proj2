#ifndef PROJ2_MATRIXCREATOR_H
#define PROJ2_MATRIXCREATOR_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <string>
#include <memory>
#include "../ServerNameSpace/Solver/MatrixSearchable.h"

static MatrixSearchable * Create(int x, int y, double chanceForWall) {
    srand (time(NULL));
    std::vector<std::string> vec;
    for(int i = 0; i < y; ++i) {
        std::string str = "";
        for(int j = 0; j < x; ++j) {
            int number = rand() % (100+((int)chanceForWall*100)) + 1;
            if (rand() % 100 < (chanceForWall*100)) {
                number = -1;
            }
            str += std::to_string(number) + ",";
        }
        str = str.substr(0, str.length()-1);
        vec.push_back(str);
    }
    int xStartVal = (rand() % x);
    int yStartVal = (rand() % y);
    std::string point = std::to_string(xStartVal) + ", " + std::to_string(yStartVal);
    vec.push_back(point);
    int xEndVal = rand() % x;
    int yEndVal = rand() % y;
    point = std::to_string(xEndVal) + ", " + std::to_string(yEndVal);
    vec.push_back(point);
    MatrixSearchable *matrixSearchable = new MatrixSearchable(vec);
    return matrixSearchable;
}

static void printMat(MatrixSearchable * mat) {
    auto a = mat->GetMatrix();
    for(int i = 0; i<a.size(); ++i) {
        for(int j = 0; j < a.at(0).size(); ++j) {
            cout<< a.at(i).at(j) << " ";
        }
        cout<< endl;
    }}

#endif //PROJ2_MATRIXCREATOR_H
