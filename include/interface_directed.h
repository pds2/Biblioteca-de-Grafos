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
public:
  Directed_IF(int n);
  virtual ~Directed_IF() = 0;
  void remove_edge(int bg, int en);
  virtual void add_edge(int bg, int en) = 0;
  virtual void add_edge(int bg, int en, int w) = 0;
  virtual int check_degree(int v) = 0;
  virtual int reflexive() = 0;
  virtual int irreflexive() = 0;
  virtual int symmetric() = 0;
  virtual int antissymetric() = 0;
  virtual int assymetric() = 0;
  virtual int transitive() = 0;
  virtual int euler_graph() = 0;
  // int has_cycle();
  // virtual int *topological_order() = 0;
  // virtual int connected() = 0;
  // virtual int bipartite() = 0;
  // virtual int get_component(int v) = 0;
};
#endif
