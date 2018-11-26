#include "interface_directed.h"

Directed_IF::Directed_IF(int n) : Graph_IF(n){
  str_con_comp = new int[n+1];
  transverse = new int*[n+1];
  this->sccs = UNDEFINED;
  for( int i=0; i<n; i++ ){
    transverse[i] = new int[n+1];
  }
}
Directed_IF::~Directed_IF(){
  delete[] str_con_comp;
  for( int i=0; i<this->order(); i++ ){
    delete[] transverse[i];
  }
  delete[] transverse;
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
