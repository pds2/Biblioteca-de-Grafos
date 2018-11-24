#include "edges.h"

int Edges::get_size(){
    return (int)v.size();
}

const std::pair<int,std::pair<int,int> >& Edges::operator [](int idx){
    if( idx >= get_size() || idx < 0 ){
        throw std::overflow_error("O indice da aresta ultrapassa as possibilidades!");
    }
    return v[idx];
}

void Edges::insert(int begin, int end, int weight){
    if( begin > 1000 ){
        throw std::overflow_error("O inicio da aresta ultrapassa as possibilidades!");
    }
    if( end > 1000 ){
        throw std::overflow_error("O fim da aresta ultrapassa as possibilidades!");
    }
    v.push_back(std::make_pair(begin, std::make_pair(end, weight)));
}
