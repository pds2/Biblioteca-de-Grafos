#ifndef DAG_H
#define DAG_H

#include "interface_directed.h"

class DAG : public Directed_IF{
public:
  DAG(int n);
  DAG(int n, Edges e);
  ~DAG();
  virtual void add_edge(int bg, int en) = 0;
  virtual void add_edge(int bg, int en, int w) = 0;
  virtual int *topological_order() = 0;
  virtual int connected() = 0;
  virtual Directed_IF *get_compressed_graph() = 0;
  virtual int bipartite() = 0;
};

#endif
