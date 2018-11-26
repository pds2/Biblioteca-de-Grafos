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
  virtual ~Directed_IF();
  virtual void add_edge(int bg, int en) =0;
  virtual void add_edge(int bg, int en, int w) =0;
  void remove_edge(int bg, int en);
  int check_degree_in(int v);
  int check_degree_out(int v);
  int has_cycle() = 0;
  virtual int *topological_order() = 0;
  virtual int connected() = 0;
  virtual int get_component(int v) = 0;
  virtual int reflexive();
  virtual int irreflexive();
  virtual int symmetric();
  virtual int antissymetric();
  virtual int assymetric();
  virtual int transitive();
};
#endif
