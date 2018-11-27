#include "interface_directed.h"
#include <bits/stdc++.h>
#define aaa std::cout<<"aqui"<<std::endl;

Directed_IF::Directed_IF(int n) : Graph_IF(n){
  str_con_comp = new int[n+1];
  transverse = new int*[n+1];
  this->visited = new int[n+1];
  this->sccs = UNDEFINED;
  for( int i=0; i<=n; i++ ){
    transverse[i] = new int[n+1];
    for(int j = 0; j <= n; j++)
        transverse[i][j] = 0;
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
  if(bg <= 0 or bg > this->order()){
     throw std::invalid_argument("Posição inicial para a aresta inválida");
  }if(en <= 0 or en > this->order()){
     throw std::invalid_argument("Posição final para a aresta inválida");
  }
  if(!this->matrix[bg][en]){
     throw std::invalid_argument("A aresta não está no grafo");
  }
  if(this->matrix[bg][en] < 0)
     this->has_negative_weight--;
  this->matrix[bg][en] = 0;
  this->transverse[en][bg] = 0;
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
        for(int j = 1; j < i; j++){
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
void Directed_IF::topological_order(int u, std::vector<int> &s){
    visited[u] = true;
    for(int i = 1; i <= this->order(); i++){
        if(this->matrix[u][i] and !visited[i])
            topological_order(i, s);
    }
    s.push_back(u);
}
int *Directed_IF::topological_order(){
  if(this->has_cycle())
      return NULL;
  std::vector<int> s;
  for(int i=0; i <= this->order(); i++){
    visited[i] = 0;
  }
  for(int i = 1; i <= this->order(); i++){
      if(!visited[i])
          topological_order(i, s);
  }
  int *aux = new int[this->order()];
  int j = 0; int i = this->order()-1;

  while(i >= 0)
      aux[j++] = s[i--];
  return aux;
}
int Directed_IF::has_cycle(){
  this->connected();
  if(this->sccs == this->order())
      return 0;
  return 1;
}
int Directed_IF::get_sccs(){
    this->kosaraju();
    return this->sccs;
}
int Directed_IF::connected(){
  this->kosaraju();
  if(this->sccs == 1)
      return 1;
  return 0;
}
void Directed_IF::kosaraju(){
    std::vector<int> pilha = std::vector<int>();
    for(int i = 0; i <= this->order(); i++){
        this->visited[i] = 0;
    }
    for(int i = 1; i <= this->order(); i++){
        if(!this->visited[i])
            DFS_KOSARAJU(i, pilha);
    }
    for(int i = 0; i <= this->order(); i++){
        this->visited[i] = 0;
    }
    this->sccs = 0;
    for(int i = this->order()-1; i >= 0; i--){
        if(!visited[pilha[i]])
            DFS_KOSARAJU_TRANSVERSE(pilha[i], ++this->sccs);
    }
}
void Directed_IF::DFS_KOSARAJU(int v, std::vector<int> &pilha){
  this->visited[v] = 1;
  for(int i = 1; i <= this->order(); i++){
      if(this->matrix[v][i] and !visited[i])
          DFS_KOSARAJU(i, pilha);
  }
  pilha.push_back(v);
}
void Directed_IF::DFS_KOSARAJU_TRANSVERSE(int v, int color){
  this->visited[v] = 1;
  this->str_con_comp[v] = color;
  for(int i = 1; i <= this->order(); i++){
      if(this->transverse[v][i] and !visited[i])
          DFS_KOSARAJU_TRANSVERSE(i, color);
  }
}
int Directed_IF::get_component(int v){
  if(v <= 0 or v > this->order()){
      throw std::overflow_error("Este vértice não está no grafo");
  }
  this->kosaraju();
  return this->str_con_comp[v];
}
