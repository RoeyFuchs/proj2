//
// Created by stav on 1/9/19.
//

#ifndef PROJ2_MYSHAREDPTRHASH_H
#define PROJ2_MYSHAREDPTRHASH_H
#include <memory.h>
#include <glob.h>
#include "../Solver/Searchable.h"
template<class P>
class SharedPtrSearchableHash{
 public:
  size_t operator()(const shared_ptr<Searchable<P>> searchable)const{
      return (size_t)searchable.get();
  }
};
template<class P>
struct SharePtrSearchableEqualValues{
 public:
  bool operator()(const  shared_ptr<Searchable<P>> searchable1,const  shared_ptr<Searchable<P>> searchable2)const{
      return searchable1->ToString()==searchable2->ToString();
  }
};
#endif //PROJ2_MYSHAREDPTRHASH_H
