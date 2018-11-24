#ifndef DIRECTED_H
#define DIRECTED_H

#include "interface_directed.h"
#include "dag.h"

class Directed : public Directed_IF{
public:
  Directed(int n);
  Directed(int n, Edges e);
  ~Directed();
  virtual void add_edge(int bg, int en);
  virtual void add_edge(int bg, int en, int w);
  // virtual int *topological_order() = 0;
  // virtual int connected() = 0;
  // virtual int has_cycle() = 0;
  // DAG *get_compressed_graph();
  // virtual int bipartite() = 0;
  // virtual int get_component(int v) = 0;
};

#endif
