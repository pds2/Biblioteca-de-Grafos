#include <bits/stdc++.h>
#include "graph_generator.h"
#include "directed_graph.h"
#include "undirected_graph.h"
#include "tree.h"
#include "dag.h"

Directed *generate_directed_graph(){
    std::srand(std::time(nullptr));
    int ordem = 1 + std::rand()%1000;
    int arestas = std::rand()%10000000;
    Directed *dg = new Directed(ordem);
    while(arestas--){
        int bg = 1 + std::rand()%ordem;
        int en = 1 + std::rand()%ordem;
        int w = 1 + std::rand()%5000000;
        int flag = std::rand()%ordem;
        if(flag >= ordem/2)
            w *= -1;
        dg->add_edge(bg, en, w);
    }
    return dg;
}
Undirected *generate_undirected_graph(){
    std::srand(std::time(nullptr));
    int ordem = 1 + std::rand()%1000;
    int arestas = std::rand()%5000000;
    Undirected *ug = new Undirected(ordem);
    while(arestas--){
        int bg = 1 + std::rand()%ordem;
        int en = 1 + std::rand()%ordem;
        int w = 1 + std::rand()%5000000;
        int flag = std::rand()%ordem;
        if(flag >= ordem/2)
            w *= -1;
        ug->add_edge(bg, en, w);
    }
    return ug;
}
