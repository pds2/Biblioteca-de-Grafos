#ifndef TREE_H
#define TREE_H

#include "interface_undirected.h"
#include "edges.h"

class Tree : public Undirected_IF{
private:
  void add_edge(int bg, int en);
  void add_edge(int bg, int en, int w);
public:
  Tree(int n, Edges e);
  ~Tree();
  int LCA(int a, int b);
};

#endif
