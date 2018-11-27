#include "interface_directed.h"

Directed_IF::Directed_IF(int n) : Graph_IF(n){
  str_con_comp = new int[n+1];
  transverse = new int*[n+1];
  this->visited = new int[n+1];
  this->sccs = UNDEFINED;
  for( int i=0; i<=n; i++ ){
    transverse[i] = new int[n+1];
  }
}
Directed_IF::~Directed_IF(){
  delete[] str_con_comp;
  for( int i=0; i<this->order(); i++ ){
    delete[] transverse[i];
  }
  delete[] transverse;
  delete[] visited;
}

void Directed_IF::remove_edge(int bg, int en){
  if(bg <= 0 or bg >= this->order()){
     throw std::invalid_argument("Posição inicial para a aresta inválida");
  }if(en <= 0 or en >= this->order()){
     throw std::invalid_argument("Posição final para a aresta inválida");
  }
  if(!this->matrix[bg][en]){
     throw std::invalid_argument("A aresta não está no grafo");
  }
  if(this->matrix[bg][en] < 0)
     this->has_negative_weight--;
  this->matrix[bg][en] = 0;
  this->matrix[0][0]--;
  this->matrix[bg][0]--;
  this->matrix[0][en]--;
}
int Directed_IF::check_degree_in(int v){
  if(v <= 0 or v > this->order()){
      throw std::overflow_error("O vértice não está no grafo");
  }
  return this->matrix[0][v];
}
int Directed_IF::check_degree_out(int v){
  if(v <= 0 or v > this->order()){
      throw std::overflow_error("O vértice não está no grafo");
  }
  return this->matrix[v][0];
}

int Directed_IF::reflexive(){
   for(int i = 1; i <= this->order(); i++){
       if(!this->matrix[i][i])
           return 0;
   }
   return 1;
}
int Directed_IF::irreflexive(){
    for(int i = 1; i <= this->order(); i++){
        if(this->matrix[i][i])
            return 0;
    }
  return 1;
}
int Directed_IF::symmetric(){
    for(int i = 1; i <= this->order(); i++){
        for(int j = 1; j <= i; j++){
            if(this->matrix[i][j] and !this->matrix[j][i])
                return 0;
            if(this->matrix[j][i] and !this->matrix[i][j])
                return 0;
        }
    }
  return 1;
}
int Directed_IF::antissymetric(){
    for(int i = 1; i <= this->order(); i++){
        for(int j = 1; j < i; i++){
            if(this->matrix[i][j] and this->matrix[j][i])
                return 0;
        }
    }
  return 1;
}
int Directed_IF::assymetric(){
  return (this->antissymetric() and this->irreflexive());
}
int Directed_IF::transitive(){
   for(int i = 1; i <= this->order(); i++){
       for(int j = 1; j <= this->order(); j++){
           if(this->matrix[i][j]){
               for(int k = 1; k <= this->order(); k++){
                   if(this->matrix[j][k] and !this->matrix[i][k])
                       return 0;
               }
           }
       }
   }
  return 1;
}

void Directed_IF::topological_order(int u, int visited[], std::stack<int> &s){
    visited[u-1] = true;
    for(int i = 1; i <= this->order(); i++){
        if(this->matrix[u][i] and !visited[i-1])
            topological_order(i, visited, s);
    }
    s.push(u);
}
int *Directed_IF::topological_order(){
  if(this->has_cycle())
      return NULL;
  std::stack<int> s;
  for( int i=0; this->order(); i++){
    visited[i] = 0;
  }
  for(int i = 0; i < this->order(); i++){
      if(!visited[i])
          topological_order(i+1, visited, s);
  }
  int i = this->order();
  while(!s.empty()){
      visited[i--] = s.top();
      s.pop();
  }
  return visited;
}
int Directed_IF::has_cycle(){
  this->connected();
  if(this->sccs == this->order())
      return 0;
  return 1;
}
int Directed_IF::connected(){
  this->kosaraju();
  return this->sccs == 1;
}
void Directed_IF::kosaraju(){
    std::stack<int> pilha;
    for( int i=0; this->order(); i++){
      visited[i] = 0;
    }
    for(int i = 1; i <= this->order(); i++){
        if(!visited[i])
            DFS_KOSARAJU(i, pilha);
    }
    for( int i=0; this->order(); i++){
      visited[i] = 0;
    }
    while(pilha.size()){
        int u = pilha.top();
        pilha.pop();
        if(!visited[u])
            SCC_KOSARAJU(u,u);
    }
}
void Directed_IF::DFS_KOSARAJU(int v, std::stack<int> &pilha){
    this->visited[v] = 1;
    for(int i = 1; i <= this->order(); i++){
        if(this->matrix[v][i] and !visited[i])
            DFS_KOSARAJU(i, pilha);
    }
    pilha.push(v);
}
void Directed_IF::SCC_KOSARAJU(int v, int cmp){
    this->visited[v] = 1;
    this->str_con_comp[v] = cmp;
    for(int i = 1; i <= this->order(); i++){
        if(this->transverse[v][i] and !visited[i])
            SCC_KOSARAJU(i, cmp);
    }
}
int Directed_IF::get_component(int v){
  if(v <= 0 or v > this->order()){
      throw std::overflow_error("Este vértice não está no grafo");
  }
  this->kosaraju();
  return this->str_con_comp[v-1];
}
