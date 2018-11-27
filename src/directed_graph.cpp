#include "directed_graph.h"

Directed::Directed(int n) : Directed_IF(n){ }
Directed::Directed(int n, Edges e) : Directed_IF(n){
  this->visited = new int[n+1];
  for( int i=0; i<e.get_size(); i++ ){
    add_edge(e[i].first, e[i].second.first, e[i].second.second);
  }
}

Directed::~Directed(){}

DAG *Directed::get_compressed_graph(){
  kosaraju();
  DAG *dag = new DAG(this->sccs);
  for(int i = 1; i <= this->order(); i++){
    for(int j = 1; j <= this->order(); j++){
        int v = this->str_con_comp[i];
        int u = this->str_con_comp[j];
        if(this->matrix[i][j] and v != u){
            dag->add_edge(v,u);
        }
    }
  }
  return dag;
}

void Directed::add_edge(int bg, int en){
  add_edge(bg, en, 1);
}
void Directed::add_edge(int bg, int en, int w){
  if(bg <= 0 or bg > this->order()){
    throw std::overflow_error("Posição inicial para a aresta inválida");
  }if(en <= 0 or en > this->order()){
    throw std::overflow_error("Posição final para a aresta inválida");
  }if(w == 0){
      throw std::invalid_argument("Valor inválido para aresta");
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
  else{
    if(w > 0)
        this->has_negative_weight--;
  }
  this->matrix[bg][en] = w;
  this->transverse[en][bg] = w;
}
