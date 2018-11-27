#include "dag.h"

DAG::DAG(int n) : Directed_IF(n){}
DAG::DAG(int n, Edges e): Directed_IF(n){
  for( int i=0; i<e.get_size(); i++ ){
    add_edge_useful(e[i].first, e[i].second.first, e[i].second.second);
  }
}
DAG::~DAG(){ }
void DAG::add_edge_useful(int head_vertex, int tail_vertex, int w){
  if(head_vertex < MIN_GRAPH_SIZE || head_vertex > this->order())
      throw std::overflow_error("Posição inicial para a aresta inválida");
  if(tail_vertex < MIN_GRAPH_SIZE || tail_vertex > this->order())
      throw std::overflow_error("Posição final para a aresta inválida");
  if(!this->matrix[head_vertex][tail_vertex]){
      this->matrix[0][0]++;
      this->matrix[head_vertex][0]++;
      this->matrix[0][tail_vertex]++;
      this->matrix[0][head_vertex]++;
      this->matrix[tail_vertex][0]++;
  }
  if(this->matrix[head_vertex][tail_vertex] >= 0){
      if(w < 0)
          this->has_negative_weight++;
  }
  this->matrix[head_vertex][tail_vertex] = w;
  this->matrix[tail_vertex][head_vertex] = w;
}
void DAG::add_edge(int head_vertex, int tail_vertex){
  add_edge(head_vertex, tail_vertex, DEFAULT_EDGE_WEIGHT);
}
void DAG::add_edge(int head_vertex, int tail_vertex, int w){
    add_edge_useful(head_vertex, tail_vertex, w);
    if( has_cycle() ){
      throw std::invalid_argument("Aresta inserida gera ciclo");
    }
}
int DAG::find_distance(int u, int v){
  find_distance(u);
  return distance[v];
}
int *DAG::find_distance(int v){
  if(v <= 0 or v > this->order()){
    throw std::overflow_error("Posição inicial para o caminhamento inválida");
  }
  int *topos = topological_order();

  for(int i = 0; i <= this->order(); i++){
        distance[i] = INF;
  }
  distance[v] = 0;

  for( int i=1; i<=this->order(); i++ ){
    if( distance[i] == INF )continue;
    for( int j=1; j<=this->order(); j++){
      if( !has_edge(topos[i], j) )continue;
      if( distance[j] > distance[topos[i]] + has_edge(topos[i], j)){
        distance[j] = distance[topos[i]] + has_edge(topos[i], j);
      }
    }
  }
  return distance;
}
