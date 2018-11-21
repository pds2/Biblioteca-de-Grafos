#ifndef INTERFACE_BASE_H
#define INTERFACE_BASE_H

#include <bits/stdc++.h>

#include "edges.h"

class Graph_IF{
protected:
  int **matrix;
  int vertices;
  int edges;
  int has_negative_weight;
  int *distance;
  int is_connected;
  int is_reflexive;
  int is_irreflexive;
  int is_symmetric;
  int is_assymetric;
  int is_antissymetric;
  int is_transitive;
public:
  Graph_IF(int n);
  virtual ~Graph_IF();
  int **get_matrix();
  int has_edge(int bg, int en);
  virtual int check_degree(int v) = 0;
  int in_degree(int v);
  int out_degree(int v);
  virtual int connected() = 0;
  virtual int has_cycle() = 0;
  int order();
  int size();
  int complete();
  int regular();
  virtual int bipartite() = 0;
  virtual int get_component(int v) = 0;
  virtual int euler_graph() = 0;
  int subgraph(Graph_IF &g);
};

#endif
