#ifndef UNDIRECTED_H
#define UNDIRECTED_H

#include "interface_undirected.h"

class Undirected : public Undirected_IF{
public:
  Undirected(int n);
  ~Undirected();
  virtual int connected();
  virtual int has_cycle();
  virtual int bipartite();
  virtual int get_component(int v);
  virtual int reflexive();
  virtual int irreflexive();
  virtual int symmetric();
  virtual int antissymetric();
  virtual int assymetric();
  virtual int transitive();
  virtual int euler_graph();
  virtual int subgraph(Graph_IF &g);
};

#endif
