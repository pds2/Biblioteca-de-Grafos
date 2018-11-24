#ifndef INTERFACE_UNDIRECTED_h
#define INTERFACE_UNDIRECTED_h

#include "interface_base.h"

class Undirected_IF : public Graph_IF{
public:
  Undirected_IF(int n);
  virtual ~Undirected_IF() = 0;
  virtual int euler_graph() = 0;
  virtual int has_cycle() = 0;
  // virtual int check_degree(int v) = 0;
  // virtual int connected() = 0;
  // virtual int bipartite() = 0;
  // virtual int get_component(int v) = 0;
};

#endif
