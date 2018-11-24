#ifndef TREE_H
#define TREE_H

#include "interface_undirected.h"
#include "edges.h"

class Tree : public Undirected_IF{
private:
  void add_edge(int head_vertex, int tail_vertex);
  void add_edge(int head_vertex, int tail_vertex, int weight);
public:
  Tree(int n, Edges e);
  ~Tree();
  int LCA(int a, int b);
};

#endif
