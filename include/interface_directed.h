#ifndef INTERFACE_DIRECTED
#define INTERFACE_DIRECTED

#include "interface_base.h"
#include <stack>
#include <vector>

class Directed_IF : public Graph_IF{
protected:
  int *str_con_comp;
  int **transverse;
  int sccs;
  int *visited;
  void kosaraju();
  void DFS_KOSARAJU(int u, int pass, int color, std::vector<int> &pilha);
  void topological_order(int u, int visited[], std::stack<int> &s);
public:
  Directed_IF(int n);
  virtual ~Directed_IF();
  virtual void add_edge(int bg, int en) =0;
  virtual void add_edge(int bg, int en, int w) =0;
  void remove_edge(int bg, int en);
  int check_degree_in(int v);
  int check_degree_out(int v);
  int has_cycle();
  int get_sccs();
  int *topological_order();
  int connected();
  int get_component(int v);
  int reflexive();
  int irreflexive();
  int symmetric();
  int antissymetric();
  int assymetric();
  int transitive();
};
#endif
