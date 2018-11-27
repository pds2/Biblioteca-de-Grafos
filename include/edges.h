#ifndef EDGES_H
#define EDGES_H

#include <vector>

class Edges {
private:
  std::vector<std::pair<int,std::pair<int, int> > > v;
public:
  int get_size();
  const std::pair<int,std::pair<int,int> >& operator [](int idx);
  void sort();
  void insert(int begin, int end, int weight);
  void insert(int begin, int end);
};

#endif
