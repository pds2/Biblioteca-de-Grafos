#include "interface_base.h"

Graph_IF::Graph_IF(int n){
  if(n <= 0 or n >= 1000){
       throw std::overflow_error("Tamanho inválido para o grafo!");
   }
   this->vertices = n;
   this->has_negative_weight = 0;
   this->distance = new int[n];
   this->matrix = new int*[n+1];
   for(int i = 0; i < n; i++){
       this->matrix[i] = new int[n+1];
       memset(this->matrix[i], 0, sizeof(sizeof(int)*(n+1)));
   }
   this->is_connected = -1;
   this->is_reflexive = -1;
   this->is_symmetric = -1;
   this->is_transitive = -1;
   this->is_irreflexive = -1;
   this->is_assymetric = -1;
   this->is_antissymetric = -1;
   this->sccs = -1;
 }

Graph_IF::~Graph_IF(){
    while(this->vertices--){
        delete [] this->matrix[this->vertices];
    }
    this->edges =  this->has_negative_weight = 0;
    delete [] this->distance;
    delete [] this->matrix;
}

int **Graph_IF::get_matrix(){
    return this->matrix;
}

int Graph_IF::has_edge(int bg, int en){
    if(bg <= 0 or bg >= this->order() or en <= 0 or en >= this->order()){
        return 0;
    }
    return this->matrix[bg][en];
}

int Graph_IF::order(){
    return this->vertices;
}
int Graph_IF::size(){
    return this->matrix[0][0];
}
int Graph_IF::complete(){
    for(int i = 1; i <= this->vertices; i++){
        int in_g = matrix[0][i];
        int out_g = matrix[i][0];
        if(in_g != out_g or in_g != this->vertices - 1)
            return 0;
    }
    return 1;
}
int Graph_IF::regular(){
    int in = matrix[0][1];
    int out = matrix[1][0];
    for(int i = 1; i <= this->vertices; i++){
        if(in != matrix[0][i])
            return 0;
        if(out != matrix[i][0])
            return 0;
    }
    return 1;
}

int Graph_IF::in_degree(int v){
  if(v <= 0 or v > this->order()){
        throw std::overflow_error("O vértice não está no grafo");
    }
  return this->matrix[0][v];
}
int Graph_IF::out_degree(int v){
  if(v <= 0 or v > this->order()){
        throw std::overflow_error("O vértice não está no grafo");
    }
  return this->matrix[v][0];
}
