#ifndef DIRECTED_GRAPH
#define DIRECTED_GRAPH
#include "graph_base.h"

class Directed : public Graph{
    private:
        int **original;
        int **transverse;
        int *scc;
        int con;
        int reflex;
        int sym;
        int trans;
        int sccs;
        void kosaraju();
        void dfs(int u, int pass, int color, std::vector<int> &pilha);
    public:
        Directed(int n);
        ~Directed();
        int in_degree(int v);
        int out_degree(int v);
        int connected();
        int get_component(int v);
        int reflexive();
        int symmetric();
        int transitive();
};

#endif
