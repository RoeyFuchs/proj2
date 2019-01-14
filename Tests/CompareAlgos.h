#define GRAPHS_FILE "graphs.txt"
#define SOLUTION_FILE "solution.txt"

#ifndef PROJ2_COMPAREALGOS_H
#define PROJ2_COMPAREALGOS_H
#include "../ServerNameSpace/Solver/BFS.h"
#include "../ServerNameSpace/Solver/DFS.h"
#include "../ServerNameSpace/Solver/AStar.h"
#include "../ServerNameSpace/Solver/BreadthFirst.h"
#include "MatrixCreator.h"
#include <iostream>
#include <fstream>

static void Run() {
    ofstream graphs;
    graphs.open (GRAPHS_FILE);
    ofstream solution;
    solution.open (SOLUTION_FILE);


    BFS* bestFirst = new BFS();
    DFS* dfs = new DFS();
    BreadthFirst* breadthFirst = new BreadthFirst();
    AStar* aStar = new AStar();
    time_t start,end;
    double dif;

    for(int i = 10; i <= 50; i+=5) {
        MatrixSearchable * mat = Create(i, i, 0);
        //shared_ptr<MatrixSearchable> smat = make_shared<MatrixSearchable>(mat);
        graphs << i << " " << i << endl;
        graphs << to_string(mat->GetInitialState()->GetState()->getX()) + "," + to_string(mat->GetInitialState()->GetState()->getY()) << endl;
        graphs << to_string(mat->GetEndPoint()->GetState()->getX()) + "," + to_string(mat->GetEndPoint()->GetState()->getY()) << endl;
        printMatStream(mat, &graphs);
        cout << "Size : " << i <<"x"<<i <<endl;
        time (&start);
        bestFirst->SearchCOP(*mat, &solution);
        time (&end);
        dif = difftime (end,start);
        cout << "best first done " << dif << endl;
        //dfs->SearchCOP(smat, &solution);
        time (&start);
        breadthFirst->SearchCOP(*mat, &solution);
        time (&end);
        dif = difftime (end,start);
        cout << "breadth first done " << dif << endl;
        time (&start);
        aStar->SearchCOP(*mat, &solution);
        time (&end);
        dif = difftime (end,start);
        cout << "a star done " << dif << endl;


    }

    graphs.close();
    solution.close();

}

#endif //PROJ2_COMPAREALGOS_H
