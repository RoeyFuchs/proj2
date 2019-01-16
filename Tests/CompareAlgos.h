#define GRAPHS_FILE "graphs.txt"
#define SOLUTION_FILE "solution.txt"

#ifndef PROJ2_COMPAREALGOS_H
#define PROJ2_COMPAREALGOS_H
#include "../Proj2/Solver/BFS.h"
#include "../Proj2/Solver/DFS.h"
#include "../Proj2/Solver/AStar.h"
#include "../Proj2/Solver/BreadthFirst.h"
#include "MatrixCreator.h"
#include <iostream>
#include <fstream>

static void Run() {
    ofstream graphs;
    graphs.open(GRAPHS_FILE);
    ofstream solution;
    solution.open(SOLUTION_FILE);

    BFS *bestFirst = new BFS();
    DFS *dfs = new DFS();
    BreadthFirst *breadthFirst = new BreadthFirst();
    AStar *aStar = new AStar();

    time_t start, end;
    double dif;

    for (int i = 55; i <= 55; i += 5) {
        shared_ptr<MatrixSearchable> smat = Create(i, i, 0.15);
        graphs << i << " " << i << endl;
        graphs << to_string(smat->GetInitialState()->GetState()->getX()) + ","
            + to_string(smat->GetInitialState()->GetState()->getY()) << endl;
        graphs << to_string(smat->GetEndPoint()->GetState()->getX()) + ","
            + to_string(smat->GetEndPoint()->GetState()->getY()) << endl;
        printMatStream(smat.get(), &graphs);
        printMat(smat.get());
        cout << "Size : " << i << "x" << i << endl;
        time(&start);
        //bestFirst->SearchCOP(smat, &solution);

        time(&end);
        dif = difftime(end, start);
        cout << "best first done " << dif << endl;
        time(&start);
        //dfs->SearchCOP(smat, &solution);
        time(&end);
        dif = difftime(end, start);
        cout << "dfs first done " << dif << endl;
        time(&start);
        // breadthFirst->SearchCOP(smat, &solution);
        time(&end);
        dif = difftime(end, start);
        cout << "breadth first done " << dif << endl;
        time(&start);
        //aStar->SearchCOP(smat, &solution);
        time(&end);
        dif = difftime(end, start);
        cout << "a star done " << dif << endl;

    }

    graphs.close();
    solution.close();

    delete bestFirst;
    delete dfs;
    delete breadthFirst;
    delete aStar;

}

#endif //PROJ2_COMPAREALGOS_H
