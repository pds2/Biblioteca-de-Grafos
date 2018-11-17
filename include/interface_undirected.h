#ifndef INTERFACE_UNDIRECTED_h
#define INTERFACE_UNDIRECTED_h

#include "interface_base.h"

class Undirected_IF : public Graph_IF{
public:
  Undirected_IF(int n);
  ~Undirected_IF();
  virtual void add_edge(int bg, int en);
  virtual void add_edge(int bg, int en, int w);
  virtual void remove_edge(int bg, int en);
  virtual int check_degree(int v);
  virtual int connected() = 0;
  virtual int has_cycle() = 0;
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
