//
// Created by stav on 1/4/19.
//
#include "Searcher.h"
#include "Searchable.h"
#include "Solution.h"
#include "StringReverserSolution.h"
#include <bits/stdc++.h>
#include <vector>
#include <memory.h>

class StringReverserSearcher:public Searcher<shared_ptr<Searchable<string>> ,shared_ptr<Solution<string>>>{
public:
    /**
     * Search
     * @param problem
     * @return solution to string problem -> reverse string
     */
    shared_ptr<Solution<string>> Search(shared_ptr<Searchable<string>>  problem){
        string str= problem->GetInitialState().GetState();
        reverse(str.begin(), str.end());
        vector<string> vec= {str};
        shared_ptr<Solution<string>> sol= make_shared<StringReverserSolution>(vec);
        return sol;
    }
};
