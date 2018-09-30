#include <bits/stdc++.h>
#include "graph_base.h"
#include "directed_graph.h"

Directed::Directed(int n) : Graph(n) {
    this->transverse = new int*[n+1];
    for(int i = 0; i <= n; i++)
        this->transverse[i] = new int[n+1];
    this->str_con_comp = new int[n];
    this->original = this->get_matrix();
    this->is_connected = -1;
    this->is_reflexive = -1;
    this->is_symmetric = -1;
    this->is_transitive = -1;
    this->is_irreflexive = -1;
    this->is_assymetric = -1;
    this->is_antissymetric = -1;
    this->sccs = -1;
}
Directed::~Directed(){
    for(int i = 0; i <= this->order(); i++)
        delete [] this->transverse[i];
    delete [] this->transverse;
    delete [] this->str_con_comp;
    this->is_connected = this->is_reflexive = this->is_symmetric = this->is_transitive = -1;
    this->is_irreflexive = this->is_assymetric = this->is_antissymetric = -1;

}
void Directed::add_edge(int bg, int en, int way){
    this->add_weighted_edge(bg, en, way, 1);
}
void Directed::add_weighted_edge(int bg, int en, int way, int weight){
    if(way == 2){
        this->Graph::add_weighted_edge(en, bg, weight);
    }
    this->Graph::add_weighted_edge(bg, en, weight);
}
int Directed::connected(){
    if(this->is_connected != -1)
        return this->is_connected;

    this->kosaraju();
    this->is_connected = 0;
    if(this->sccs == 1)
        this->is_connected = 1;
    return this->is_connected;
}
void Directed::kosaraju(){
    std::vector<int> pilha;
    memset(this->str_con_comp, 0, sizeof(this->str_con_comp));
    for(int i = 1; i <= this->order(); i++){
        if(!this->str_con_comp[i-1]){
            this->dfs(i, 1, 1, pilha);
        }
    }
    memset(this->str_con_comp, 0, sizeof(this->str_con_comp));
    this->sccs = 1;
    for(int i = this->order()-1; i > 0; i--){
        if(!this->str_con_comp[pilha[i]-1]){
            dfs(pilha[i], 2, this->sccs, pilha);
            this->sccs++;
        }
    }
}
void Directed::dfs(int u, int pass, int color, std::vector<int> &pilha){
    this->str_con_comp[u-1] = color;
    int *neighboors;
    if(pass == 1){
        neighboors = this->original[u];
    }else{
        neighboors = this->transverse[u];
    }
    for(int j = 1; j < this->order(); j++){
        if(!neighboors[j])
            continue;
        int v = neighboors[j];
        if(!this->str_con_comp[v-1]){
            dfs(v,pass,color,pilha);
        }
    }
    pilha.push_back(u);
}
Directed *Directed::get_compressed_graph(){
    Directed *DAG = new Directed(this->order());
    if(!this->has_cycle()){
        *DAG = *this;
        return DAG;
    }
    for(int i = 1; i <= this->order(); i++){
        for(int j = 1; j <= this->order(); j++){
            if(str_con_comp[i-1] != str_con_comp[j-1] and this->original[i][j]){
                DAG->add_weighted_edge(i, j, 1, this->original[i][j]);
            }
        }
    }
    return DAG;
}
void Directed::topological_order_useful(int u, int visited[], std::stack<int> &s){
    visited[u-1] = true;
    for(int i = 1; i <= this->order(); i++){
        if(this->original[u][i] and !visited[i-1])
            topological_order_useful(i, visited, s);
    }
    s.push(u);
}
int *Directed::topological_order(){
    if(this->has_cycle())
        return NULL;

    int *visited = new int[this->order()];
    std::stack<int> s;
    for(int i = 0; i < this->order(); i++)
        visited[i] = false;
    for(int i = 0; i < this->order(); i++){
        if(!visited[i])
            topological_order_useful(i+1, visited, s);
    }
    int i = 0;
    while(!s.empty()){
        visited[i++] = s.top();
        s.pop();
    }
    return visited;
}
int Directed::has_cycle(){
    if(this->sccs == -1)
        this->connected();

    if(this->sccs == this->order())
        return 1;
    return 0;
}
int Directed::get_component(int v){
    if(v > this->order()){
        std::cout << "This vertex is not on the graph" << std::endl;
        return -1;
    }
    if(this->str_con_comp[v-1] != -1)
        return this->str_con_comp[v-1];
    this->kosaraju();
    return this->str_con_comp[v-1];
}
int Directed::in_degree(int v){
    if(v > this->order()){
        std::cout << "This vertex is not on the graph" << std::endl;
        return 0;
    }
    return this->original[0][v];
}
int Directed::out_degree(int v){
    if(v > this->order()){
        std::cout << "This vertex is not on the graph" << std::endl;
        return 0;
    }
    return this->original[v][0];
}
int Directed::reflexive(){
    if(this->is_reflexive != -1)
        return this->is_reflexive;

    for(int i = 1; i <= this->order(); i++){
        if(!this->original[i][i])
            return this->is_reflexive = 0;
    }
    return this->is_reflexive = 1;
}
int Directed::symmetric(){
    if(this->is_symmetric != -1)
        return this->is_symmetric;

    for(int i = 1; i <= this->order(); i++){
        for(int j = 1; j <= i; j++){
            if(this->original[i][j] and !this->original[j][i])
                return this->is_symmetric = 0;
            if(this->original[j][i] and !this->original[i][j])
                return this->is_symmetric = 0;
        }
    }
    return this->is_symmetric = 1;
}
int Directed::transitive(){
    if(this->is_transitive != -1)
        return this->is_transitive;

    for(int i = 1; i <= this->order(); i++){
        for(int j = 1; j <= this->order(); j++){
            if(this->original[i][j]){
                for(int k = 1; k <= this->order(); k++){
                    if(this->original[j][k] and !this->original[i][k])
                        return this->is_transitive = 0;
                }
            }
        }
    }
    return this->is_transitive = 1;
}
int Directed::irreflexive(){
    if(this->is_irreflexive != -1)
        return this->is_irreflexive;

    for(int i = 1; i <= this->order(); i++){
        if(this->original[i][i])
            return this->is_irreflexive = 0;
    }
    return this->is_irreflexive = 1;
}
int Directed::antissymetric(){
    if(this->is_antissymetric != -1)
        return this->is_antissymetric;

    for(int i = 1; i <= this->order(); i++){
        for(int j = 1; j < i; i++){
            if(this->original[i][j] and this->original[j][i])
                return this->is_antissymetric = 0;
        }
    }
    return this->is_antissymetric = 1;
}
int Directed::assymetric(){
    return (this->antissymetric() and this->irreflexive());
}
