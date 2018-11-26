#include "directed_graph.h"

Directed::Directed(int n) : Directed_IF(n){
  this->visited = new int[n+1];
}
Directed::Directed(int n, Edges e) : Directed_IF(n){
  this->visited = new int[n+1];
  for( int i=0; i<e.get_size(); i++ ){
    add_edge(e[i].first, e[i].second.first, e[i].second.second);
  }
}

Directed::~Directed(){
  delete visited;
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
  this->matrix[bg][en] = w;
  this->transverse[en][bg] = w;
}
void Directed::topological_order(int u, int visited[], std::stack<int> &s){
    visited[u-1] = true;
    for(int i = 1; i <= this->order(); i++){
        if(this->matrix[u][i] and !visited[i-1])
            topological_order(i, visited, s);
    }
    s.push(u);
}
int *Directed::topological_order(){
  if(this->has_cycle())
      return NULL;
  std::stack<int> s;
  memset(visited,0,sizeof(visited));
  for(int i = 0; i < this->order(); i++){
      if(!visited[i])
          topological_order(i+1, visited, s);
  }
  int i = 0;
  while(!s.empty()){
      visited[i++] = s.top();
      s.pop();
  }
  return visited;
}
int Directed::has_cycle(){
  this->connected();
  if(this->sccs == this->order())
      return 0;
  return 1;
}
int Directed::connected(){
  this->kosaraju();
  return this->sccs == 1;
}
void Directed::kosaraju(){
    std::stack<int> pilha;
    memset(visited, 0, sizeof(visited));
    for(int i = 1; i <= this->order(); i++){
        if(!visited[i])
            DFS_KOSARAJU(i, pilha);
    }
    memset(visited, 0, sizeof(visited));
    while(pilha.size()){
        int u = pilha.top();
        pilha.pop();
        if(!visited[u])
            SCC_KOSARAJU(u,u);
    }
}
void Directed::DFS_KOSARAJU(int v, std::stack<int> &pilha){
    this->visited[v] = 1;
    for(int i = 1; i <= this->order(); i++){
        if(this->matrix[v][i] and !visited[i])
            DFS_KOSARAJU(i, pilha);
    }
    pilha.push(v);
}
void Directed::SCC_KOSARAJU(int v, int cmp){
    this->visited[v] = 1;
    this->str_con_comp[v] = cmp;
    for(int i = 1; i <= this->order(); i++){
        if(this->transverse[v][i] and !visited[i])
            SCC_KOSARAJU(i, cmp);
    }
}
int Directed::get_component(int v){
  if(v <= 0 or v > this->order()){
      throw std::overflow_error("Este vértice não está no grafo");
  }
  this->kosaraju();
  return this->str_con_comp[v-1];
}
