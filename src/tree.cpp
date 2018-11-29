#include "tree.h"
#include "edges.h"
#include <queue>

// Constructors
// Creates a tree with n vertex and set of edges e

Tree::Tree(int n, int new_root, Edges e) : Undirected_IF(n){
  parents = NULL;
  if(new_root < MIN_GRAPH_SIZE || new_root > this->order()){
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
  if( !connected() ){
    throw std::invalid_argument("O grafo dado nao e conexo");
  }
}

int Tree::get_root(){
  return root;
}
void Tree::set_root(int new_root){
  if(new_root < MIN_GRAPH_SIZE || new_root > this->order()){
    throw std::overflow_error("Posição invalida para a raiz");
  }
  if( parents != NULL ){
    delete[] parents;
    parents = NULL;
  }
  root = new_root;
}

// Destructor
Tree::~Tree(){
  if( parents != NULL ){
    delete[] parents;
  }
}

// Inserts edge with desired weight in the graph, connecting vertex head and tail
void Tree::add_edge(int head_vertex, int tail_vertex, int w){
  if( !has_edge(head_vertex, tail_vertex) ){
    matrix[0][0]--;
  }
  add_edge_useful(head_vertex, tail_vertex, w);
  add_edge_useful(tail_vertex, head_vertex, w);
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
  if(v < MIN_GRAPH_SIZE || v > this->order()){
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

int Tree::num_level(){
  std::queue<std::pair<int,int> >q;
  const int end_level = -1;
  int par, u, levels=0;

  q.push(std::make_pair(root, root));
  q.push(std::make_pair(end_level, end_level));

  while( q.size() ){
    u = q.front().first;
    par = q.front().second;
    q.pop();
    if( u == end_level ){
      levels++;
      if( q.size() ){
        q.push(std::make_pair(end_level, end_level));
      }
      continue;
    }
    for( int i=1; i<=this->order(); i++ ){
      if( has_edge(u, i) && i != par ){
        q.push(std::make_pair(i, u));
      }
    }
  }
  return levels;
}

int Tree::find_distance(int u, int v){
  find_distance(u);
  return distance[v];
}
int *Tree::find_distance(int v){
  for( int i=1; i<=this->order(); i++ ){
    distance[i] = -1;
  }
  distance[v] = 0;
  dfs_distance(v, v);
  return distance;
}

void Tree::dfs_distance(int current, int par){
  for( int i=1; i<=this->order(); i++ ){
    if( has_edge(current, i) && i!=par ){
      distance[i] = distance[current] +1;
      dfs_distance(i, current);
    }
  }
}
