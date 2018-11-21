#include "edges.h"

int Edges::get_size(){
  return (int)v.size();
}

const std::pair<int,std::pair<int,int> >& Edges::operator [](int idx){
  if( idx >= get_size() || idx < 0 ){
    // throw
  }
  return v[idx];
}

void Edges::insert(int begin, int end, int weight){
  if( begin > 1000 || end > 1000 ){
    // throw
  }
  v.push_back(std::make_pair(begin, std::make_pair(end, weight)));
}
