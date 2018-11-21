#include "interface_directed.h"

Directed_IF::Directed_IF(int n) : Graph_IF(n){
  str_con_comp = new int[n];
  transverse = new int*[n+1];
  for( int i=0; i<n; i++ ){
    transverse[i] = new int[n+1];
  }
  sccs = -1;
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
int Directed_IF::check_degree(int v){
  if(v <= 0 or v > this->order()){
      throw std::overflow_error("O vértice não está no grafo");
  }
  return this->matrix[v][0];
}

int Directed_IF::reflexive(){
  if(this->is_reflexive != -1)
       return this->is_reflexive;

   for(int i = 1; i <= this->order(); i++){
       if(!this->matrix[i][i])
           return this->is_reflexive = 0;
   }
   return this->is_reflexive = 1;
}
int Directed_IF::irreflexive(){
  if(this->is_irreflexive != -1)
        return this->is_irreflexive;

    for(int i = 1; i <= this->order(); i++){
        if(this->matrix[i][i])
            return this->is_irreflexive = 0;
    }
  return this->is_irreflexive = 1;
}
int Directed_IF::symmetric(){
  if(this->is_symmetric != -1)
        return this->is_symmetric;

    for(int i = 1; i <= this->order(); i++){
        for(int j = 1; j <= i; j++){
            if(this->matrix[i][j] and !this->matrix[j][i])
                return this->is_symmetric = 0;
            if(this->matrix[j][i] and !this->matrix[i][j])
                return this->is_symmetric = 0;
        }
    }
  return this->is_symmetric = 1;
}
int Directed_IF::antissymetric(){
  if(this->is_antissymetric != -1)
        return this->is_antissymetric;

    for(int i = 1; i <= this->order(); i++){
        for(int j = 1; j < i; i++){
            if(this->matrix[i][j] and this->matrix[j][i])
                return this->is_antissymetric = 0;
        }
    }
  return this->is_antissymetric = 1;
}
int Directed_IF::assymetric(){
  return (this->antissymetric() and this->irreflexive());
}
int Directed_IF::transitive(){
  if(this->is_transitive != -1)
       return this->is_transitive;

   for(int i = 1; i <= this->order(); i++){
       for(int j = 1; j <= this->order(); j++){
           if(this->matrix[i][j]){
               for(int k = 1; k <= this->order(); k++){
                   if(this->matrix[j][k] and !this->matrix[i][k])
                       return this->is_transitive = 0;
               }
           }
       }
   }
  return this->is_transitive = 1;
}

int Directed_IF::euler_graph(){
  for(int i = 1; i <= this->vertices; i++){
    if(this->matrix[i][0] != this->matrix[0][i]) return 0;
    if(this->matrix[i][0]%2) return 0;
    if(this->matrix[0][i]%2) return 0;
  }
  return 1;
}
