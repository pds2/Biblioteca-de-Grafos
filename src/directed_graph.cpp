#include "directed_graph.h"

Directed::Directed(int n) : Directed_IF(n){}
Directed::Directed(int n, Edges e) : Directed_IF(n){
  for( int i=0; i<e.get_size(); i++ ){
    add_edge(e[i].first, e[i].second.first, e[i].second.second);
  }
}

void Directed::add_edge(int bg, int en){
  add_edge(bg, en, 1);
}
void Directed::add_edge(int bg, int en, int w){
  if(bg <= 0 or bg >= this->order()){
    throw std::overflow_error("Posição inicial para a aresta inválida");
  }if(en <= 0 or en >= this->order()){
    throw std::overflow_error("Posição final para a aresta inválida");
  }
  if(!this->matrix[bg][en]){
    this->matrix[0][0]++;
    this->matrix[bg][0]++;
    this->matrix[0][en]++;
  }
  if(this->matrix[bg][en] >= 0){
    if(w < 0)
        this->has_negative_weight++;
  }
  this->matrix[bg][en] = w;
}

// TODO
// int Directed::*topological_order(){
//     return 0;
// }
// int Directed::connected(){
//     return 0;
// }
// int Directed::has_cycle(){
//     return 0;
// }
// DAG *get_compressed_graph(){
//     return NULL;
// }
// int Directed::bipartite(){
//     return 0;
// }
// int Directed::get_component(int v){
//     return 0;
// }
