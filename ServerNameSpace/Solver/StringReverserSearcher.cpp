//
// Created by stav on 1/4/19.
//
#include "Searcher.h"
#include "Searchable.h"
#include <bits/stdc++.h>

class StringReverserSearcher:public Searcher<string, string>{
    /**
     * Search
     * @param problem
     * @return solution to string problem -> reverse string
     */
    string Search(Searchable <string> problem){
        string str= problem.GetInitialState();
        reverse(str.begin(), str.end());
        return str;
    }
};
