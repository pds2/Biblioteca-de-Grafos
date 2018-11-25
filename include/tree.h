#ifndef TREE_H
#define TREE_H

#include "interface_undirected.h"
#include "edges.h"

class Tree : public Undirected_IF{
private:
  int root;
  int *parents;
  void add_edge(int head_vertex, int tail_vertex);
  void add_edge(int head_vertex, int tail_vertex, int weight);
  void dfs_parent(int current, int par);
public:
  Tree(int n, int new_root, Edges e);
  ~Tree();
  int get_root();
  void set_root(int new_root);
  int LCA(int a, int b);
  int get_parent(int v);
};

#endif
