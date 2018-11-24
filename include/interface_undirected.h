#ifndef INTERFACE_UNDIRECTED_h
#define INTERFACE_UNDIRECTED_h

#include "interface_base.h"

class Undirected_IF : public Graph_IF {
    public:
        Undirected_IF(int n);
        virtual ~Undirected_IF();
        int check_degree(int v);
        virtual int bipartite();
        virtual int connected();
        virtual int euler_graph();
        virtual int get_component(int v);
        virtual int has_cycle();
    private:
        int bipartite_DFS(int curr, int *visited, int *colour);
        void connected_DFS(int curr, int *visited, int &connected_num);
        int find_cycle_DFS(int curr, int *visited, int parent);
};

#endif
