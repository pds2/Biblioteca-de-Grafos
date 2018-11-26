#include "undirected_graph.h"

// Constructors
// Creates a undirected graph with n vertex
Undirected::Undirected(int n) : Undirected_IF(n){ }

// Creates a undirected graph with n vertex and set of edges e
Undirected::Undirected(int n, Edges e) : Undirected_IF(n){
    for( int i=0; i<e.get_size(); i++ )
        add_edge(e[i].first, e[i].second.first, e[i].second.second);

}

// Destructor
Undirected::~Undirected() { }

// Inserts edge with weight 1 in the graph, connecting vertex head and tail
void Undirected::add_edge(int head_vertex, int tail_vertex){
    this->add_edge(head_vertex, tail_vertex, DEFAULT_EDGE_WEIGHT);
}

// Inserts edge with desired weight in the graph, connecting vertex head and tail
void Undirected::add_edge(int head_vertex, int tail_vertex, int w){
    // Treats overflow cases for edge position
    if(head_vertex < MIN_GRAPH_SIZE || head_vertex > this->order())
        throw std::overflow_error("Posição inicial para a aresta inválida");
    if(tail_vertex < MIN_GRAPH_SIZE || tail_vertex > this->order())
        throw std::overflow_error("Posição final para a aresta inválida");

    if(!this->matrix[head_vertex][tail_vertex]) {
        this->matrix[0][0]++;
        this->matrix[head_vertex][0]++;
        this->matrix[0][tail_vertex]++;
        this->matrix[0][head_vertex]++;
        this->matrix[tail_vertex][0]++;
    }
    // Treats negative weight cases
    if(this->matrix[head_vertex][tail_vertex] >= 0) {
        if(w < 0)
            this->has_negative_weight++;
    }
    this->matrix[head_vertex][tail_vertex] = w;
    this->matrix[tail_vertex][head_vertex] = w;
    _union(tail_vertex, head_vertex);
}

// Removes edge that connects vertex head and tail
void Undirected::remove_edge(int head_vertex, int tail_vertex){
    // Treats overflow cases for edge position
    if(head_vertex < MIN_GRAPH_SIZE || head_vertex > this->order())
        throw std::overflow_error("Posição inicial para a aresta inválida");
    if(head_vertex < MIN_GRAPH_SIZE || tail_vertex > this->order())
        throw std::overflow_error("Posição final para a aresta inválida");

    if (this->matrix[head_vertex][tail_vertex] != 0) {
        this->matrix[0][0]--;
        this->matrix[head_vertex][0]--;
        this->matrix[0][tail_vertex]--;
        this->matrix[0][head_vertex]--;
        this->matrix[tail_vertex][0]--;
        this->matrix[head_vertex][tail_vertex] = 0;
        this->matrix[tail_vertex][head_vertex] = 0;
    }
}
int Undirected::find(int vertex){
    //The find function finds the Id of a specific vertex, we use it on union
    if(this->id[vertex]) return get_id(vertex);
    return id[vertex] = find(id[vertex]);
}

void Undirected::_union(int vertex_1, int vertex_2){
    //The union funciontion is used to match the Id of two different vertices
    vertex_1 = find(vertex_1);
    vertex_2 = find(vertex_2);
    int aux;
    if(vertex_1 < vertex_2){
        aux = vertex_1;
        vertex_1 = vertex_2;
        vertex_2 = aux;
    }
    if(vertex_1 != vertex_2)
        id[vertex_1] = vertex_2;
}
