#include "undirected_graph.h"
#include "tree.h"

// Constructors
// Creates a undirected graph with n vertex
Undirected::Undirected(int n) : Undirected_IF(n){
  rep = new int[n+1];
}

// Creates a undirected graph with n vertex and set of edges e
Undirected::Undirected(int n, Edges e) : Undirected_IF(n){
    for( int i=0; i<e.get_size(); i++ )
        add_edge(e[i].first, e[i].second.first, e[i].second.second);
    rep = new int[n+1];
}

// Destructor
Undirected::~Undirected(){
  delete[] rep;
}

// Inserts edge with weight 1 in the graph, connecting vertex head and tail
void Undirected::add_edge(int head_vertex, int tail_vertex){
    this->add_edge(head_vertex, tail_vertex, DEFAULT_EDGE_WEIGHT);
}

// Inserts edge with desired weight in the graph, connecting vertex head and tail
void Undirected::add_edge(int head_vertex, int tail_vertex, int w){
    // Treats overflow cases for edge position
    if( !has_edge(head_vertex, tail_vertex) ){
      matrix[0][0]--;
    }
    add_edge_useful(head_vertex, tail_vertex, w);
    add_edge_useful(tail_vertex, head_vertex, w);
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

void Undirected::build(){
  for( int i=0; i<=this->order(); i++ ){
    rep[i] = i;
  }
}
void Undirected::unite(int u, int v){
  rep[find(u)] = find(v);
}
int Undirected::find(int a){
  return rep[a] == a ? a : rep[a] = find(rep[a]);
}

Tree *Undirected::kruskal(){
  //The kruskal algorithm is used to find one minimal sub-tree from a graph
  build();
  Edges ed;
  for( int i=1; i<=this->order(); i++ ){
    for( int j=i+1; j<=this->order(); j++ ){
      if( !has_edge(i, j) )continue;
      ed.insert(i, j, has_edge(i, j));
    }
  }
  ed.sort();

  Edges new_tree;
  for( int i=0; i<ed.get_size(); i++ ){
    if( find(ed[i].first) != find(ed[i].second.first) ){
      unite(ed[i].first, ed[i].second.first);
      new_tree.insert(ed[i].first, ed[i].second.first, ed[i].second.second);
    }
  }

  Tree *ret = new Tree(this->order(), 1, new_tree);

  return ret;
}
