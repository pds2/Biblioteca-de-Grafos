#ifndef INTERFACE_UNDIRECTED_h
#define INTERFACE_UNDIRECTED_h

#include "interface_base.h"

class Undirected_IF : public Graph_IF {
    public:
        Undirected_IF(int n);
        virtual ~Undirected_IF();
        int check_degree(int v);
        // A bipartite graph (or bigraph) is one whose vertices can be divided into
        // two disjoint and independent sets U and V such that
        // every edge connects a vertex in U to one in V
        virtual int bipartite();
        virtual int connected();
        // Eulerian trail/path is a trail which visits every edge exactly once.
        // Eulerian cycle is an Eulerian trail which starts and ends on the same vertex.
        // Eulerian graph has the prorpety that every vertex is of even degree
        virtual int euler_graph();
        virtual int get_component(int v);
        virtual int has_cycle();
    private:
        int bipartite_DFS(int curr, int *visited, int *colour);
        void connected_DFS(int curr, int *visited, int &connected_num);
        int find_cycle_DFS(int curr, int *visited, int parent);

};

#endif
