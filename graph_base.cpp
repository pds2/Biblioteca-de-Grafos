#include <bits/stdc++.h>
#include "graph_base.h"

const int INF = 0x3f3f3f3f;
typedef std::pair<int, int> ii;

Graph::Graph(int n){
    if(n <= 0 or n >= 1000){
        throw std::overflow_error("Tamanho inválido para o grafo!");
    }
    this->vertices = n;
    this->has_negative_w = 0;
    this->distance = new int[n];
    this->matrix = new int*[n+1];
    for(int i = 0; i < n; i++){
        this->matrix[i] = new int[n+1];
        memset(this->matrix[i], 0, sizeof(this->matrix[i]));
    }

}
Graph::~Graph(){
    while(this->vertices--){
        delete [] this->matrix[this->vertices];
    }
    this->edges =  this->has_negative_w = 0;
    delete [] this->distance;
    delete [] this->matrix;
}
int **Graph::get_matrix(){
    return this->matrix;
}
void Graph::add_weighted_edge(int bg, int en, int w){
    if(bg <= 0 or bg >= this->order()){
        throw std::overflow_error("Posição inicial para a aresta inválida");
    }if(en <= 0 or bg >= this->order()){
        throw std::overflow_error("Posição final para a aresta inválida");
    }
    if(!this->matrix[bg][en]){
        this->matrix[0][0]++;
        this->matrix[bg][0]++;
        this->matrix[0][en]++;
    }
    if(this->matrix[bg][en] >= 0){
        if(w < 0)
            this->has_negative_w++;
    }
    this->matrix[bg][en] = w;
}
void Graph::add_edge(int bg, int en){
    this->add_weighted_edge(bg, en, 1);
}
int Graph::has_edge(int bg, int en){
    if(bg <= 0 or bg >= this->order() or en <= 0 or en >= this->order())
        return 0;
    return this->matrix[bg][en];
}
void Graph::remove_edge(int bg, int en){
    if(bg <= 0 or bg >= this->order()){
        throw std::invalid_argument("Posição inicial para a aresta inválida");
    }if(en <= 0 or bg >= this->order()){
        throw std::invalid_argument("Posição final para a aresta inválida");
    }
    if(bg > this->vertices or en > this->vertices or !this->matrix[bg][en]){
        throw std::invalid_argument("A aresta não está no grafo");
    }
    if(this->matrix[bg][en] < 0)
        this->has_negative_w--;
    this->matrix[bg][en] = 0;
    this->matrix[0][0]--;
    this->matrix[bg][0]--;
    this->matrix[0][en]--;
}
int Graph::check_degree(int v){
    if(v <= 0 or v > this->order()){
        throw std::overflow_error("O vértice não está no grafo");
    }
    return this->matrix[v][0];
}
int Graph::order(){
    return this->vertices;
}
int Graph::size(){
    return this->matrix[0][0];
}
int Graph::complete(){
    for(int i = 1; i <= this->vertices; i++){
        int in_g = matrix[0][i];
        int out_g = matrix[i][0];
        if(in_g != out_g or in_g != this->vertices - 1)
            return 0;
    }
    return 1;
}
int Graph::regular(){
    int in = matrix[0][1];
    int out = matrix[1][0];
    for(int i = 1; i <= this->vertices; i++){
        if(in != matrix[0][i])
            return 0;
        if(out != matrix[i][0])
            return 0;
    }
    return 1;
}
int Graph::bipartite(){
    int colors[this->vertices];
    memset(colors, 0, sizeof(colors));
    std::stack<int> s;
    s.push(1);
    colors[0] = 1;
    while(!s.empty()){
        while(!s.empty()){
            int u = s.top(); s.pop();
            int at = colors[u-1];
            for(int i = 1; i <= this->vertices; i++){
                if(this->matrix[u][i]){
                    if(colors[i-1] and at == colors[i-1])
                        return 0;
                    if(at == 1)
                        colors[i-1] = 2;
                    else
                        colors[i-1] = 1;
                    s.push(i);
                }
            }
        }
        for(int i = 0; i < this->vertices; i++){
            if(!colors[i]){
                s.push(i);
                colors[i] = 1;
                break;
            }
        }
    }
    return 1;
}
int Graph::dijkstra(int bg, int en){
    if(bg <= 0 or bg >= this->order()){
        throw std::overflow_error("O vértice inicial para o caminhamento é inválido");
    }if(en <= 0 or bg >= this->order()){
        throw std::overflow_error("O vértice final para o caminhamento é inválido");
    }if(this->has_negative_w){
        throw std::logic_error("O grafo possui valores negativos, utilize o algorítmo *");
    }
    memset(this->distance, INF, sizeof(this->distance));
    this->distance[bg] = 0;
    std::priority_queue<ii> q;
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
    return this->distance[en];
}
int Graph::euler_graph(){
    // verificar se é conexo
    for(int i = 1; i <= this->vertices; i++){
        if(this->matrix[i][0]%2)
            return 0;
        if(this->matrix[0][i]%2)
            return 0;
    }
    return 1;
}
int Graph::subgraph(Graph &g){
    if(g.vertices > this->vertices)
        return 0;

    for(int i = 1; i <= g.vertices; i++){
        for(int j = 1; j <= g.vertices; j++){
            if(g.matrix[i][j] and !this->matrix[i][j])
                return 0;
        }
    }
    return 1;
}
