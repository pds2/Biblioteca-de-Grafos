#ifndef DIRECTED_H
#define DIRECTED_H

#include "interface_directed.h"

class Directed : public Directed_IF{
public:
  Directed(int n);
  ~Directed();
  virtual int *topological_order();
  virtual int connected();
  virtual Directed_IF *get_compressed_graph();
  virtual int bipartite();
  virtual int get_component(int v);
  virtual int euler_graph();
  virtual int subgraph(Graph_IF &g);
};

#endif
