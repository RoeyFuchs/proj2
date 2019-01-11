//
// Created by stav on 1/11/19.
//

#ifndef PROJ2_FILECACHEMANAGERTESTS_H
#define PROJ2_FILECACHEMANAGERTESTS_H

#include "../ServerNameSpace/CacheManager/FileCacheManager.h"
#include "../ServerNameSpace/Solver/StringReverserSearcher.h"
#include <memory.h>
#include <vector>
/*
  void RunTests(){
      //please clean cache file first

      vector<string> vec;
      StringReverserSearcher stringAlgo;
      shared_ptr<Solution<string>> stringSol;
      shared_ptr<FileCacheManager<string,string>> cacheManager= make_shared<FileCacheManager<string,string>>();

      //initialise problems and solutions
      vec={"123456"};
      shared_ptr<Searchable<string>> stringProblem1 =make_shared<StringReverserSearchable>(vec);
      stringSol= stringAlgo.Search(stringProblem1);
      cacheManager->AddSolution(stringProblem1,stringSol);

      vec={"abcdef"};
      shared_ptr<Searchable<string>> stringProblem2 =make_shared<StringReverserSearchable>(vec);
      stringSol= stringAlgo.Search(stringProblem2);
      cacheManager->AddSolution(stringProblem2,stringSol);

      vec={"0011"};
      shared_ptr<Searchable<string>> stringProblem3 =make_shared<StringReverserSearchable>(vec);
      stringSol= stringAlgo.Search(stringProblem3);
      cacheManager->AddSolution(stringProblem3,stringSol);

      vec={"aabb"};
      shared_ptr<Searchable<string>> stringProblem4 =make_shared<StringReverserSearchable>(vec);
      stringSol= stringAlgo.Search(stringProblem4);
      cacheManager->AddSolution(stringProblem4,stringSol);

      vec={"2233"};
      shared_ptr<Searchable<string>> stringProblem5=make_shared<StringReverserSearchable>(vec);
      stringSol= stringAlgo.Search(stringProblem5);
      cacheManager->AddSolution(stringProblem5,stringSol);

      int i=1;


      stringSol= cacheManager->GetSolution(stringProblem1);
      if(stringSol->ToString()=="654321"){
          cout<<"test "<< i<<"passed"<<endl;
      }else{
          cout<<"test "<< i<<"failed"<<endl;
      }
i++;
      stringSol= cacheManager->GetSolution(stringProblem2);
      if(stringSol->ToString()=="fedcba"){
          cout<<"test "<< i<<"passed"<<endl;
      }else{
          cout<<"test "<< i<<"failed"<<endl;
      }
      i++;
      stringSol= cacheManager->GetSolution(stringProblem3);
      if(stringSol->ToString()=="1100"){
          cout<<"test "<< i<<"passed"<<endl;
      }else{
          cout<<"test "<< i<<"failed"<<endl;
      }
      i++;
      stringSol= cacheManager->GetSolution(stringProblem4);
      if(stringSol->ToString()=="bbaa"){
          cout<<"test "<< i<<"passed"<<endl;
      }else{
          cout<<"test "<< i<<"failed"<<endl;
      }
      i++;
      stringSol= cacheManager->GetSolution(stringProblem5);
      if(stringSol->ToString()=="3322"){
          cout<<"test "<< i<<"passed"<<endl;
      }else{
          cout<<"test "<< i<<"failed"<<endl;
      }

  }
*/
#endif //PROJ2_FILECACHEMANAGERTESTS_H
