#ifndef GRAPH_BASE
#define GRAPH_BASE

class Graph{
  protected:
    int edges;
    int **matrix;
    int *distance;
    int has_negative_w;
    int vertices;
    int dijkstra(int bg, int en);
  public:
    Graph(int n);
    ~Graph();
    int **get_matrix();
    void add_edge(int bg, int en);
    void add_weighted_edge(int bg, int en, int w);
    int has_edge(int bg, int en);
    void remove_edge(int bg, int en);
    int check_degree(int v);
    int order();
    int size();
    int complete();
    int regular();
    int bipartite();
    int euler_graph();
    int subgraph(Graph &g);
    int funcao_teste();
};

#endif
