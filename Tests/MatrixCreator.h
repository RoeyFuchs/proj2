#ifndef PROJ2_MATRIXCREATOR_H
#define PROJ2_MATRIXCREATOR_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <string>
#include <memory>
#include "../Proj2/Solver/MatrixSearchable.h"

static shared_ptr<MatrixSearchable> Create(int x, int y, double chanceForWall) {
    srand (time(NULL));
    std::vector<std::string> vec;
    for(int i = 0; i < y; ++i) {
        std::string str = "";
        for(int j = 0; j < x; ++j) {
            int number = rand() % 100 + 1;
            if (rand() % 100 < (chanceForWall*100)) {
                number = -1;
            }
            str += std::to_string(number) + ",";
        }
        str = str.substr(0, str.length()-1);
        vec.push_back(str);
    }
    int xStartVal = 0;
    int yStartVal = 0;
    std::string point = std::to_string(xStartVal) + ", " + std::to_string(yStartVal);
    vec.push_back(point);
    int xEndVal = x-1;
    int yEndVal = y-1;
    point = std::to_string(xEndVal) + ", " + std::to_string(yEndVal);
    vec.push_back(point);
    shared_ptr<MatrixSearchable> a = make_shared<MatrixSearchable>(vec);
    return a;
}

static void printMat(MatrixSearchable * mat) {
    auto a = mat->GetMatrix();
    for(int i = 0; i<a.size(); ++i) {
        for(int j = 0; j < a.at(0).size(); ++j) {
            cout<< a.at(i).at(j) << " ";
        }
        cout<< endl;
    }
}

static void printMatStream(MatrixSearchable * mat, ostream* ostream) {
    auto a = mat->GetMatrix();
    for(int i = 0; i<a.size(); ++i) {
        for(int j = 0; j < a.at(0).size(); ++j) {
            *ostream<< a.at(i).at(j);
            if(!(j == a.at(0).size()-1)) {
                *ostream<<  ", ";
            }
        }
        *ostream<< endl;
    }
}

#endif //PROJ2_MATRIXCREATOR_H
