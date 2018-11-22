#ifndef UNDIRECTED_H
#define UNDIRECTED_H

#include "interface_undirected.h"

class Undirected : public Undirected_IF{
public:
  Undirected(int n);
  Undirected(int n, Edges e);
  void add_edge(int bg, int en);
  void add_edge(int bg, int en, int w);
  void remove_edge(int bg, int en);
  ~Undirected();
};

#endif
