#include "interface_undirected.h"

Undirected_IF::Undirected_IF(int n) : Graph_IF(n){}

Undirected_IF::~Undirected_IF(){ }

int Undirected_IF::euler_graph(){
  for(int i = 1; i <= this->vertices; i++){
      if(this->matrix[i][0]%2)
          return 0;
      if(this->matrix[0][i]%2)
          return 0;
  }
  return 1;
}
