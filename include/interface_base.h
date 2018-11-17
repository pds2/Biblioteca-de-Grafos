#ifndef INTERFACE_BASE_H
#define INTERFACE_BASE_H

#include <bits/stdc++.h>

class Graph_IF{
protected:
  int **matrix;
  int vertices;
  int edges;
  int has_negative_weight;
  int *str_con_comp;
  int *distance;
  int is_connected;
  int is_reflexive;
  int is_irreflexive;
  int is_symmetric;
  int is_assymetric;
  int is_antissymetric;
  int is_transitive;
  int sccs;
public:
  Graph_IF(int n);
  ~Graph_IF();
  int **get_matrix();
  virtual void add_edge(int bg, int en) = 0;
  virtual void add_edge(int bg, int en, int w) = 0;
  int has_edge(int bg, int en);
  virtual void remove_edge(int bg, int en) = 0;
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
  virtual int reflexive() = 0;
  virtual int irreflexive() = 0;
  virtual int symmetric() = 0;
  virtual int antissymetric() = 0;
  virtual int assymetric() = 0;
  virtual int transitive() = 0;
  virtual int euler_graph() = 0;
  virtual int subgraph(Graph_IF &g) = 0;
};

#endif
