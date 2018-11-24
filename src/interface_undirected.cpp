#include "interface_undirected.h"

// Constructor
Undirected_IF::Undirected_IF(int n) : Graph_IF(n) {}

// Destructor (implementation from parent's virtual)
Undirected_IF::~Undirected_IF() { }

// From the first vertex in the matrix, will verify if the graph can be coloured with 2 colours
int Undirected_IF::bipartite() {
    // Mark all the this->vertices as not visited, and vertex colour as blank
    int *visited = new int[this->vertices+1];
    int *colour = new int[this->vertices+1];
    for(int i = 1; i <= this->vertices; i++) {
        visited[i] = 0;
        colour[0] = 0;
    }

    // Initializes first vertex as visited and with the first colour
    visited[1] = 1;
    colour[1] = 1;

    if (bipartite_DFS(1, visited, colour)) {
        return 1;
    }
    return 0;
}

// In an undirected graph, the in_degree = out_degree
int Undirected_IF::check_degree(int v) {
    return in_degree(v);
}

// From the first vertex in the matrix, will verify if all the vertex are connected
int Undirected_IF::connected() {
    // Mark all the this->vertices as not visited
    int *visited = new int[this->vertices+1];
    int connected_num = 0;
    for(int i = 1; i <= this->vertices; i++)
        visited[i] = 0;

    for(int v=1; v<=this->vertices; v++) {
        if (visited[v] == 0)
            connected_DFS(v, visited, connected_num);
    }

    // If the total number of visited vertex is
    // the total of vertex in the graph, it is connected
    if(connected_num == this->vertices)
        return 1;

    return 0;
}

// Cycles through all vertex in graph, returns if an odd degree is found
// (which means graph is not Eulerian)
int Undirected_IF::euler_graph() {
  for (int i = 1; i <= this->vertices; i++) {
      if (this->matrix[i][0]%2)
          return 0;
      if (this->matrix[0][i]%2)
          return 0;
  }
  return 1;
}

int Undirected_IF::has_cycle() {
    // Mark all the this->vertices as not visited
    int *visited = new int[this->vertices+1];
    for(int i = 1; i <= this->vertices; i++)
        visited[i] = 0;

    for(int v=1; v<=this->vertices; v++) {
        if (visited[v] == 0)
            if (find_cycle_DFS(v, visited, -1) == 1)
                return 1;
    }

    return 0;
}

//TODO: implement
int Undirected_IF::get_component(int v) { return 0; }

/* ----------------------------------- Auxiliary methods ----------------------------------- */
// Auxiliary bipartite() method, it investigates all adjacent vertex
// to verify if they were visited and can be coloured, in a Depth First Search
int Undirected_IF::bipartite_DFS(int curr, int *visited, int *colour) {
    for(int i = 1; i <= this->vertices; i++){
        if (Graph_IF::has_edge(curr, i)){
            if(visited[curr] == 0){
                // Mark vertex as visited and colour as opposite to its parent
                visited[i] = 1;

                if(colour[curr] == 1){
                    colour[i] = 2;
                } else {
                    colour[i] = 1;
                }

                // If  subtree rooted at vertex i is not bipartite, the graph is not
                if (bipartite_DFS(i, visited, colour) == 0)
                    return 0;
            }
            // if two adjacent are coloured with same colour, the graph is not bipartite
            else if (colour[curr] == colour[i])
                return 0;
        }
    }
    return 1;
}

// Auxiliary connected() method, it marks all adjacent vertex as visited and
// increases the counter of connected vertex, in a Depth First Search
void Undirected_IF::connected_DFS(int curr, int *visited, int &connected_num) {
    // Mark the current node as visited and increase counter
    visited[curr] = 1;
    connected_num++;

    // Iterate through all non-visited adjacent to this vertex
    for(int v=1; v<=this->vertices; v++) {
        if (curr != v && Graph_IF::has_edge(curr, v)) {
            if(visited[v] == 0)
                connected_DFS(v, visited, connected_num);
        }
    }
}

// Auxiliary has_cycle() method, it investigates all adjacent vertex
// to verify if they were visited, in a Depth First Search
int Undirected_IF::find_cycle_DFS(int curr, int *visited, int parent) {
    // Mark the current node as visited
    visited[curr] = 1;

    // Iterate through all adjacent to this vertex
    for(int v=1; v<=this->vertices; v++) {
        // If an adjacent is not visited, then try to find cycle for it
        if (Graph_IF::has_edge(curr, v)) {
            if(visited[v] == 0)
                if (find_cycle_DFS(v, visited, curr))
                    return 1;
        }

        // If an adjacent is visited and not parent of current vertex, then there is a cycle.
        else if (v != parent)
           return 1;
    }
    return 0;
}
