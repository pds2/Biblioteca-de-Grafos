#ifndef UNDIRECTED_H
#define UNDIRECTED_H

#include "interface_undirected.h"
#include "tree.h"

class Undirected : public Undirected_IF{
    private:
        int *rep;
        void build();
        void unite(int u, int v);
        int find(int a);
    public:
        Undirected(int n);
        Undirected(int n, Edges e);
        ~Undirected();
        void add_edge(int edge_head, int edge_tail);
        void add_edge(int edge_head, int edge_tail, int weight);
        void remove_edge(int edge_head, int edge_tail);
        Tree *kruskal();
};

#endif
