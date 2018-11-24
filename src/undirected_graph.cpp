#include "undirected_graph.h"

Undirected::Undirected(int n) : Undirected_IF(n){ }
Undirected::Undirected(int n, Edges e) : Undirected_IF(n){
  for( int i=0; i<e.get_size(); i++ ){
    add_edge(e[i].first, e[i].second.first, e[i].second.second);
  }
}

void Undirected::add_edge(int bg, int en){
  add_edge(bg, en, 1);
}
void Undirected::add_edge(int bg, int en, int w){
  if(bg <= 0 or bg >= this->order()){
    throw std::overflow_error("Posição inicial para a aresta inválida");
  }if(en <= 0 or en >= this->order()){
    throw std::overflow_error("Posição final para a aresta inválida");
  }
  if(!this->matrix[bg][en]){
    this->matrix[0][0]++;
    this->matrix[bg][0]++;
    this->matrix[0][en]++;
    this->matrix[0][bg]++;
    this->matrix[en][0]++;
  }
  if(this->matrix[bg][en] >= 0){
    if(w < 0)
        this->has_negative_weight++;
  }
  this->matrix[bg][en] = w;
  this->matrix[en][bg] = w;
}

//TODO
// void Undirected::remove_edge(int bg, int en){
//
// }
