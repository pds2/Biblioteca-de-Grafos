#ifndef INTERFACE_UNDIRECTED_h
#define INTERFACE_UNDIRECTED_h

#include "interface_base.h"

class Undirected_IF : public Graph_IF{
public:
  Undirected_IF(int n);
  virtual ~Undirected_IF();
  virtual int check_degree(int v);
  virtual int connected();
  virtual int has_cycle();
  virtual int bipartite();
  virtual int get_component(int v);
  virtual int euler_graph();
};

#endif
