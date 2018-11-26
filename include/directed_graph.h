#ifndef DIRECTED_H
#define DIRECTED_H

#include "interface_directed.h"
#include "dag.h"

class Directed : public Directed_IF{
private:
  int *visited;
  void kosaraju();
  void DFS_KOSARAJU(int u, std::stack<int> &pilha);
  void SCC_KOSARAJU(int v, int cmp);
  void topological_order(int u, int visited[], std::stack<int> &s);
public:
  Directed(int n);
  Directed(int n, Edges e);
  ~Directed();
  virtual void add_edge(int bg, int en);
  virtual void add_edge(int bg, int en, int w);
  virtual int *topological_order();
  virtual int connected();
  virtual int has_cycle();
  DAG *get_compressed_graph();
  virtual int get_component(int v);
};

#endif
