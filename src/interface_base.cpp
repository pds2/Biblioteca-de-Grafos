#include "interface_base.h"
#include "constants.h"

Graph_IF::Graph_IF(int n) {
        if(n < MIN_GRAPH_SIZE or n > MAX_GRAPH_SIZE) {
                throw std::overflow_error("Tamanho inválido para o grafo!");
        }
        this->vertices = n;
        this->id = new int[n+1];
        this->has_negative_weight = 0;
        this->distance = new int[n+1];
        this->matrix = new int*[n+1];
        for(int i = 0; i <= n; i++) {
                this->id[i] = i;
                this->matrix[i] = new int[n+1];
                for( int j=0; j<=n; j++ ){
                        matrix[i][j] = 0;
                }
        }
        this->is_connected = UNDEFINED;
        this->is_bipartite = UNDEFINED;
        this->is_eulerian = UNDEFINED;
}

Graph_IF::~Graph_IF() {
        while(this->vertices--) {
                delete [] this->matrix[this->vertices];
        }
        this->edges = this->has_negative_weight = 0;
        delete [] this->distance;
        delete [] this->matrix;
}

int **Graph_IF::get_matrix() {
        return this->matrix;
}

int Graph_IF::get_id(int vertex) {
        return this->id[vertex];
}

int Graph_IF::has_edge(int bg, int en) {
        if(bg <= 0 or bg > this->order() or en <= 0 or en > this->order()) {
          throw std::overflow_error("Aresta invalida");
        }
        return this->matrix[bg][en];
}

int Graph_IF::order() {
        return this->vertices;
}
int Graph_IF::size() {
        return this->matrix[0][0];
}
int Graph_IF::find_distance(int bg, int en){
    find_distance(bg);
    return distance[en];
}
int *Graph_IF::find_distance(int u){
  if(this->has_negative_weight){
      throw std::invalid_argument("Não é possível realizar o dijkstra em Grafos com arestas de valores negativos");
  }
  dijkstra(u);
  return distance;
}
int *Graph_IF::dijkstra(int bg){
  if(bg <= 0 or bg > this->order()){
    throw std::overflow_error("Posição inicial para o caminhamento inválida");
  }
  for( int i=0; i<=this->order(); i++ ){
    distance[i] = 0;
  }
  this->distance[bg] = 0;
  std::priority_queue<std::pair<int,int> > q;
  q.push(std::make_pair(0, bg));
  while(!q.empty()){
      int dis = -q.top().first;
      int u = q.top().second;
      q.pop();
      if(dis > this->distance[u])
          continue;
      for(int i = 1; i <= this->vertices; i++){
          int w = this->matrix[u][i];
          if(!this->matrix[u][i])
              continue;
          if(this->distance[i] > this->distance[u] + w){
              this->distance[i] = this->distance[u] + w;
              q.push(std::make_pair(-this->distance[i], i));
          }
      }
  }
  return this->distance;
}
int Graph_IF::complete() {
        for(int i = 1; i <= this->vertices; i++) {
                int in_g = matrix[0][i];
                int out_g = matrix[i][0];
                if(in_g != out_g or in_g != this->vertices - 1)
                        return FALSE;
        }
        return TRUE;
}
int Graph_IF::regular() {
        int in = matrix[0][1];
        int out = matrix[1][0];
        for(int i = 1; i <= this->vertices; i++) {
                if(in != matrix[0][i])
                        return FALSE;
                if(out != matrix[i][0])
                        return FALSE;
        }
        return TRUE;
}
int Graph_IF::subgraph(Graph_IF &g) {
        if(g.vertices > this->vertices)
                return FALSE;

        for(int i = 1; i <= g.vertices; i++) {
                for(int j = 1; j <= g.vertices; j++) {
                        if(g.matrix[i][j] and !this->matrix[i][j])
                                return FALSE;
                }
        }
        return TRUE;
}
