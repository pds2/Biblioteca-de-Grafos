#ifndef DAG_H
#define DAG_H

#include "interface_directed.h"

class DAG : public Directed_IF{
public:
  DAG(int n);
  DAG(int n, Edges e);
  ~DAG();
  virtual void add_edge(int bg, int en);
  virtual void add_edge(int bg, int en, int w);
  virtual int *topological_order();
  virtual int connected();
  virtual Directed_IF *get_compressed_graph();
  virtual int bipartite();
};

#endif
