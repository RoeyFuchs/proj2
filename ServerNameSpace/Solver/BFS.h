
#ifndef PROJ2_BFS_H
#define PROJ2_BFS_H

#include <queue>
#include <list>
#include <algorithm>
#include "Searcher.h"
#include "Solution.h"
#include "../Utils/Comperators.h"
#include "../Utils/Utils.h"

class BFS : public Searcher<vector<vector<int>>, string> {
  State<vector<vector<int>>> initialState;
  State<vector<vector<int>>> endState;


  string Search(vector<vector<int>> problem) {
    std::priority_queue<State<vector<vector<int>>>, vector<State<vector<vector<int>>>>, CompareStep> open;
    open.push(this->initialState);
    std::list<State<vector<vector<int>>>> closed;
    while (!open.empty()) {
        State<vector<vector<int>>> n = open.top();
        open.pop();
        closed.push_back(n);
        if(n == this->endState) {
            //done
        }
        list<State<vector<vector<int>>>> successor = GetAllPossiableStates();
        for(State<vector<vector<int>>>& s: successor) {
            bool foundInClosed = (std::find(closed.begin(), closed.end(), s) != closed.end());
            if (!CheckIfValueInSidePriorityQueue<State<vector<vector<int>>>>(s, open) && foundInClosed) {
                s.SetComeFrom(n);
                open.push(s);
            } else {
                
            }
        }
    }

  }

};
#endif //PROJ2_BFS_H
