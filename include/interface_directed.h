#ifndef INTERFACE_DIRECTED
#define INTERFACE_DIRECTED

#include "interface_base.h"

class Directed_IF : public Graph_IF{
public:
  Directed_IF(int n);
  ~Directed_IF();
  virtual void add_edge(int bg, int en);
  virtual void add_edge(int bg, int en, int w);
  virtual void remove_edge(int bg, int en);
  virtual int check_degree(int v);
  virtual int has_cycle();
  virtual int *topological_order() = 0;
  virtual int connected() = 0;
  virtual Directed_IF *get_compressed_graph() = 0;
  virtual int bipartite() = 0;
  virtual int get_component(int v) = 0;
  virtual int reflexive();
  virtual int irreflexive();
  virtual int symmetric();
  virtual int antissymetric();
  virtual int assymetric();
  virtual int transitive();
  virtual int euler_graph() = 0;
  virtual int subgraph(Graph_IF &g) = 0;
};
#endif
