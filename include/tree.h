#ifndef TREE_H
#define TREE_H

#include "interface_undirected.h"

class Tree : public Undirected_IF{
public:
  Tree(int n);
  ~Tree();
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
