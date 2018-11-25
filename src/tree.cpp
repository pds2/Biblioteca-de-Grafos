#include "tree.h"
#include "edges.h"

// Constructors
// Creates a tree with n vertex and set of edges e

Tree::Tree(int n, int new_root, Edges e) : Undirected_IF(n){
  parents = NULL;
  if(new_root < MIN_GRAPH_SIZE || new_root >= this->order()){
    throw std::overflow_error("Posição invalida para a raiz");
  }
  root = new_root;
  if( e.get_size() != n-1 ){
    throw std::invalid_argument("Numero de arestas invalido para a Arvore");
  }
  for( int i=0; i<e.get_size(); i++ )
      add_edge(e[i].first, e[i].second.first, e[i].second.second);


  if( has_cycle() ){
    throw std::invalid_argument("Arestas dadas geram ciclo");
  }
}

int Tree::get_root(){
  return root;
}
void Tree::set_root(int new_root){
  if(new_root < MIN_GRAPH_SIZE || new_root >= this->order()){
    throw std::overflow_error("Posição invalida para a raiz");
  }
  if( parents != NULL ){
    delete[] parents;
  }
  root = new_root;
}

// Destructor
Tree::~Tree(){
  if( parents != NULL ){
    delete[] parents;
  }
}

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

// Lowest Commom Ancestor
int Tree::LCA(int a, int b){

    get_parent(1);

    bool *visited = new bool[this->order()+1];
    for( int i=0; i<=this->order(); i++ ){
      visited[i] = false;
    }

    while( a!=root ){
      visited[a] = true;
      a = parents[a];
    }

    while( b!=root ){
      if( visited[b] == true){
        delete[] visited;
        return b;
      }
      b = parents[b];
    }

    delete[] visited;
    return root;
}

int Tree::get_parent(int v){
  if(v < MIN_GRAPH_SIZE || v >= this->order()){
      throw std::overflow_error("Aresta invalida");
  }
  if( parents != NULL ){
    return parents[v];
  }
  parents = new int[this->order()+1];

  dfs_parent(root, root);

  return parents[v];
}

void Tree::dfs_parent(int current, int par){
  parents[current] = par;
  for( int i=1; i<=this->order(); i++ ){
    if( !this->matrix[current][i] || i==par )continue;
    dfs_parent(i, current);
  }
}
