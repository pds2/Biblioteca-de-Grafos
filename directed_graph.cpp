#include <bits/stdc++.h>
#include "graph_base.h"
#include "directed_graph.h"

Directed::Directed(int n) : Graph(n) {
    this->transverse = new int*[n+1];
    for(int i = 0; i <= n; i++)
        this->transverse[i] = new int[n+1];
    this->scc = new int[n];
    this->original = this->get_matrix();
    this->con = -1;
    this->reflex = -1;
    this->sym = -1;
    this->trans = -1;
    this->sccs = -1;
}
Directed::~Directed(){
    for(int i = 0; i <= this->order(); i++)
        delete [] this->transverse[i];
    delete [] this->transverse;
    delete [] this->scc;
    this->con = this->reflex = this->sym = this->trans = -1;

}
int Directed::connected(){
    if(this->con != -1)
        return this->con;
    this->kosaraju();
    this->con = 0;
    if(this->sccs == 1)
        this->con = 1;
    return this->con;
}
void Directed::kosaraju(){
    std::vector<int> pilha;
    memset(this->scc, 0, sizeof(this->scc));
    for(int i = 1; i <= this->order(); i++){
        if(!this->scc[i-1]){
            this->dfs(i, 1, 1, pilha);
        }
    }
    memset(this->scc, 0, sizeof(this->scc));
    this->sccs = 1;
    for(int i = this->order()-1; i > 0; i--){
        if(!this->scc[pilha[i]-1]){
            dfs(pilha[i], 2, this->sccs, pilha);
            this->sccs++;
        }
    }
}
void Directed::dfs(int u, int pass, int color, std::vector<int> &pilha){
    this->scc[u-1] = color;
    int *vizinhos; // Englês TODO: Englês
    if(pass == 1){
        vizinhos = this->original[u];
    }else{
        vizinhos = this->transverse[u];
    }
    for(int j = 1; j < this->order(); j++){
        if(!vizinhos[j])
            continue;
        int v = vizinhos[j];
        if(!this->scc[v-1]){
            dfs(v,pass,color,pilha);
        }
    }
    pilha.push_back(u);
}
int Directed::get_component(int v){
    if(v > this->vertices){
        std::cout << "This vertex is not on the graph" << std::endl;
        return -1;
    }
    if(this->scc[v-1] != -1)
        return this->scc[v-1];
    this->kosaraju();
    return this->scc[v-1];
}
int Directed::in_degree(int v){
    if(v > this->vertices){
        std::cout << "This vertex is not on the graph" << std::endl;
        return 0;
    }
    return this->original[0][v];
}
int Directed::out_degree(int v){
    if(v > this->vertices){
        std::cout << "This vertex is not on the graph" << std::endl;
        return 0;
    }
    return this->original[v][0];
}
int Directed::reflexive(){
    if(this->reflex != -1)
        return this->reflex;
    for(int i = 1; i <= this->order(); i++){
        if(!this->original[i][i])
            return this->reflex = 0;
    }
    return this->reflex = 1;
}
int Directed::symmetric(){
    if(this->sym != -1)
        return this->sym;
    for(int i = 1; i <= this->order(); i++){
        for(int j = 1; j <= i; j++){
            if(this->original[i][j] and !this->original[j][i])
                return this->sym = 0;
            if(this->original[j][i] and !this->original[i][j])
                return this->sym = 0;
        }
    }
    return this->sym = 1;
}
int Directed::transitive(){
    if(this->trans != -1)
        return this->trans;
    for(int i = 1; i <= this->order(); i++){
        for(int j = 1; j <= this->order(); j++){
            if(this->original[i][j]){
                for(int k = 1; k <= this->order(); k++){
                    if(this->original[j][k] and !this->original[i][k])
                        return this->trans = 0;
                }
            }
        }
    }
    return this->trans = 1;
}
