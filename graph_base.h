#ifndef GRAPH_BASE
#define GRAPH_BASE

class Graph{
  private:
    int edges;
    int **matrix;
    int *cc;
    int *d;
    int vertices;
  public:
    Graph(int n);
    ~Graph();
    void add_edge(int bg, int en);
    void add_weighted_edge(int bg, int en, int w);
    void remove_edge(int bg, int en);
    int check_grau(int v);
    // int connected();
    int get_component(int v);
    int colouring();
    int order();
    int size();
    int complete();
    int regular();
    int bipartite();
    int dijkstra(int bg, int en);
    int euler_graph();
    int subgraph(Graph &g);
};

#endif
