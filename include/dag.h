#ifndef DAG_H
#define DAG_H

#include "interface_directed.h"

class DAG : public Directed_IF{
private:
  // void add_edge_useful(int head_vertex, int tail_vertex, int w);
public:
  DAG(int n);
  DAG(int n, Edges e);
  ~DAG();
  virtual void add_edge(int head_vertex, int tail_vertex);
  virtual void add_edge(int head_vertex, int tail_vertex, int w);
  virtual int find_distance(int u, int v) override;
  virtual int *find_distance(int v) override;
};

#endif
