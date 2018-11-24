#ifndef UNDIRECTED_H
#define UNDIRECTED_H

#include "interface_undirected.h"

class Undirected : public Undirected_IF{
    public:
        Undirected(int n);
        Undirected(int n, Edges e);
        ~Undirected();
        void add_edge(int edge_head, int edge_tail);
        void add_edge(int edge_head, int edge_tail, int weight);
        void remove_edge(int edge_head, int edge_tail);
};

#endif
