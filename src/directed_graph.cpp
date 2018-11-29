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
  add_edge_useful(bg, en, w);
  this->transverse[en][bg] = w;
}
