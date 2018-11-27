#include "edges.h"
#include <stdexcept>
#include <algorithm>

int Edges::get_size(){
  return (int)v.size();
}

const std::pair<int,std::pair<int,int> >& Edges::operator [](int idx){
  if( idx >= get_size() || idx < 0 ){
    throw std::range_error("Indice invalido");
  }
  return v[idx];
}

void Edges::insert(int begin, int end, int weight){
  if( begin > 1000 || end > 1000 || begin <= 0 || end <= 0 ){
    throw std::overflow_error("Aresta invalida");
  }
  v.push_back(std::make_pair(begin, std::make_pair(end, weight)));
}

void Edges::insert(int begin, int end){
  insert(begin, end, 1);
}

void Edges::sort(){
  std::sort(v.begin(), v.end(), compare_edges);
}

bool compare_edges(std::pair<int,std::pair<int, int> > p1, std::pair<int,std::pair<int, int> > p2){
  return p1.second.second < p2.second.second;
}
