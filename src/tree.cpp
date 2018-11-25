#include "tree.h"
#include "edges.h"

// Constructors
// Creates a tree with n vertex and set of edges e
//TODO - implement
Tree::Tree(int n, Edges e) : Undirected_IF(n){
    if( e.get_size() != n-1 ){
        // throw
    }
    for( int i=0; i<e.get_size(); i++ )
        add_edge(e[i].first, e[i].second.first, e[i].second.second);


    if( has_cycle() ){
        // throw
    }
}

// Destructor
Tree::~Tree() { }

// Inserts edge with weight 1 in the tree, connecting vertex head and tail
void Tree::add_edge(int head_vertex, int tail_vertex){
    add_edge(head_vertex, tail_vertex, DEFAULT_EDGE_WEIGHT);
}

// Inserts edge with desired weight in the graph, connecting vertex head and tail
void Tree::add_edge(int head_vertex, int tail_vertex, int w){
    if(head_vertex < MIN_GRAPH_SIZE || head_vertex >= this->order())
        throw std::overflow_error("Posição inicial para a aresta inválida");
    if(tail_vertex < MIN_GRAPH_SIZE || tail_vertex >= this->order())
        throw std::overflow_error("Posição final para a aresta inválida");

    if(!this->matrix[head_vertex][tail_vertex]){
        this->matrix[0][0]++;
        this->matrix[head_vertex][0]++;
        this->matrix[0][tail_vertex]++;
        this->matrix[0][head_vertex]++;
        this->matrix[tail_vertex][0]++;
    }
    if(this->matrix[head_vertex][tail_vertex] >= 0){
        if(w < 0)
            this->has_negative_weight++;
    }
    this->matrix[head_vertex][tail_vertex] = w;
    this->matrix[tail_vertex][head_vertex] = w;
}

//TODO - implement
int Tree::LCA(int a, int b){
    return 0;
}
