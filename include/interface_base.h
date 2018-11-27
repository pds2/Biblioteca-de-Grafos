#ifndef INTERFACE_BASE_H
#define INTERFACE_BASE_H

#include <bits/stdc++.h>

#include "edges.h"
#include "constants.h"

class Graph_IF {

    protected:
        // This matrix has size V+1 * V+1, where V is the number of vertex
        // The line index 0, has the in-degree of each vertex
        // The column index 0, has the out-degree of each vertex
        // The item [0, 0] has the number of edges in the matrix
        int **matrix;
        // Number of vertex in the graph
        int vertices;
        // Number of edges in the graph
        int edges;
        // Count of how many edges with negative weight exist in a graph
        int has_negative_weight;
        // The distance between two vertices in a graph is
        // the number of edges in a shortest pathconnecting them
        int *distance;
        //The identity of a vertix is the root of the former tree of the 
        //component graph, and is the same for all vertices os the same component graph
        int *id;
        int is_connected;
        int is_bipartite;
        int is_eulerian;
        int *dijkstra(int bg);
    public:
        Graph_IF(int n);
        virtual ~Graph_IF();
        virtual int find_distance(int bg, int en);
        virtual int *find_distance(int u);
        int **get_matrix();
        int get_id(int vertix);
        int has_edge(int bg, int en);
        int order();
        int size();
        int complete();
        int regular();
        int subgraph(Graph_IF &g);
        // A graph is connected when there is a path between every pair of vertices.
        // In a connected graph, there are no unreachable vertices
        virtual int connected() = 0;

        // A graph has a cycle when a vertex is reachable from itself,
        // through a path of edges and vertices
        virtual int has_cycle() = 0;
        virtual int get_component(int v) = 0;
};

#endif
