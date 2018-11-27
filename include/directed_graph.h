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
  DAG *get_compressed_graph();
};

#endif
