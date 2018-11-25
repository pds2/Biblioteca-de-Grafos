#include "interface_base.h"

Graph_IF::Graph_IF(int n) {
        if(n < MIN_GRAPH_SIZE or n >= MAX_GRAPH_SIZE) {
                throw std::overflow_error("Tamanho inválido para o grafo!");
        }
        this->vertices = n;
        this->has_negative_weight = 0;
        this->distance = new int[n];
        this->matrix = new int*[n+1];
        for(int i = 0; i < n; i++) {
                this->matrix[i] = new int[n+1];
                memset(this->matrix[i], 0, sizeof(sizeof(int)*(n+1)));
        }
        this->is_connected = UNDEFINED;
        this->is_reflexive = UNDEFINED;
        this->is_symmetric = UNDEFINED;
        this->is_transitive = UNDEFINED;
        this->is_irreflexive = UNDEFINED;
        this->is_assymetric = UNDEFINED;
        this->is_bipartite = UNDEFINED;
        this->is_eulerian = UNDEFINED;
}

Graph_IF::~Graph_IF() {
        while(this->vertices--) {
                delete [] this->matrix[this->vertices];
        }
        this->edges = this->has_negative_weight = UNDEFINED;
        delete [] this->distance;
        delete [] this->matrix;
}

int **Graph_IF::get_matrix() {
        return this->matrix;
}

int Graph_IF::has_edge(int bg, int en) {
        if(bg <= 0 or bg >= this->order() or en <= 0 or en >= this->order()) {
                return 0;
        }
        return this->matrix[bg][en];
}

int Graph_IF::order() {
        return this->vertices;
}
int Graph_IF::size() {
        return this->matrix[0][0];
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

int Graph_IF::in_degree(int v) {
        if(v <= MIN_GRAPH_SIZE or v > this->order()) {
                throw std::overflow_error("O vértice não está no grafo");
        }
        return this->matrix[0][v];
}
int Graph_IF::out_degree(int v) {
        if(v <= MIN_GRAPH_SIZE or v > this->order()) {
                throw std::overflow_error("O vértice não está no grafo");
        }
        return this->matrix[v][0];
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
