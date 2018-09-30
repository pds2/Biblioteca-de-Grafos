#ifndef DIRECTED_GRAPH
#define DIRECTED_GRAPH
#include <stack>
#include <vector>
#include "graph_base.h"

class Directed : public Graph{
    private:
        int **original;
        int **transverse;
        int *str_con_comp;
        int is_connected;
        int is_reflexive;
        int is_irreflexive;
        int is_symmetric;
        int is_assymetric;
        int is_antissymetric;
        int is_transitive;
        int sccs;
        void kosaraju();
        void topological_order_useful(int u, int visited[], std::stack<int> &s);
        void dfs(int u, int pass, int color, std::vector<int> &pilha);
    public:
        Directed(int n);
        ~Directed();
        void add_edge(int bg, int en, int way);
        void add_weighted_edge(int bg, int en, int way, int weight);
        int in_degree(int v);
        int out_degree(int v);
        int has_cycle();
        int *topological_order();
        int connected();
        Directed *get_compressed_graph();
        int get_component(int v);
        int reflexive();
        int irreflexive();
        int symmetric();
        int antissymetric();
        int assymetric();
        int transitive();
};

#endif
