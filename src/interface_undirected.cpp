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
        visited[i] = FALSE;
        colour[i] = FALSE;
    }

    // Initializes first vertex as visited and with the first colour
    visited[1] = TRUE;
    colour[1] = 1;

    if (bipartite_DFS(1, visited, colour)) {
        this->is_bipartite = TRUE;
        return TRUE;
    }
    this->is_bipartite = FALSE;
    return FALSE;
}

// From the first vertex in the matrix, will verify if all the vertex are connected
int Undirected_IF::connected() {
    // Mark all the this->vertices as not visited
    int *visited = new int[this->vertices+1];
    int connected_num = 0;
    for(int i = 1; i <= this->vertices; i++)
        visited[i] = FALSE;

    for(int v=1; v<=this->vertices; v++) {
        if (visited[v] == FALSE)
            connected_DFS(v, visited, connected_num);
    }

    // If the total number of visited vertex is
    // the total of vertex in the graph, it is connected
    if(connected_num == this->vertices) {
        this->is_connected = TRUE;
        return TRUE;
    }
    this->is_connected = FALSE;
    return FALSE;
}

// Cycles through all vertex in graph, returns if an odd degree is found
// (which means graph is not Eulerian)
int Undirected_IF::euler_graph() {
  for (int i = 1; i <= this->vertices; i++) {
      if (this->matrix[i][0]%2 || this->matrix[0][i]%2){
          this->is_eulerian = FALSE;
          return FALSE;
      }
  }
  this->is_eulerian = TRUE;
  return TRUE;
}

int Undirected_IF::has_cycle() {
    // Mark all the this->vertices as not visited
    int *visited = new int[this->vertices+1];
    for(int i = 1; i <= this->vertices; i++){
        visited[i] = FALSE;
    }

    for(int v=1; v<=this->vertices; v++) {
        if (visited[v] == FALSE){
            if (find_cycle_DFS(v, visited, UNDEFINED) == TRUE){
                return TRUE;
            }
        }
    }

    return FALSE;
}

/* ----------------------------------- Auxiliary methods ----------------------------------- */
// Auxiliary bipartite() method, it investigates all adjacent vertex
// to verify if they were visited and can be coloured, in a Depth First Search
int Undirected_IF::bipartite_DFS(int curr, int *visited, int *colour) {
    for(int i = 1; i <= this->vertices; i++){
        if (Graph_IF::has_edge(curr, i)){
            if(visited[i] == FALSE){
                // Mark vertex as visited and colour as opposite to its parent
                visited[i] = TRUE;

                if(colour[curr] == 1){
                    colour[i] = 2;
                } else if(colour[curr] == 2){
                    colour[i] = 1;
                }

                // If  subtree rooted at vertex i is not bipartite, the graph is not
                if (bipartite_DFS(i, visited, colour) == FALSE)
                    return FALSE;
            }else if (colour[curr] == colour[i]){
              return FALSE;
            }
        }
    }
    return TRUE;
}

// Auxiliary connected() method, it marks all adjacent vertex as visited and
// increases the counter of connected vertex, in a Depth First Search
void Undirected_IF::connected_DFS(int curr, int *visited, int &connected_num) {
    // Mark the current node as visited and increase counter
    visited[curr] = TRUE;
    connected_num++;

    // Iterate through all non-visited adjacent to this vertex
    for(int v=1; v<=this->vertices; v++) {
        if (curr != v && Graph_IF::has_edge(curr, v)) {
            if(visited[v] == FALSE)
                connected_DFS(v, visited, connected_num);
        }
    }
}

// Auxiliary has_cycle() method, it investigates all adjacent vertex
// to verify if they were visited, in a Depth First Search
int Undirected_IF::find_cycle_DFS(int curr, int *visited, int parent) {
    // Mark the current node as visited
    visited[curr] = TRUE;

    // Iterate through all adjacent to this vertex
    for(int v=1; v<=this->vertices; v++) {
        // If an adjacent is not visited, then try to find cycle for it
        if (Graph_IF::has_edge(curr, v)) {
            if(visited[v] == FALSE){
                if (find_cycle_DFS(v, visited, curr)){
                    return TRUE;
                }
            }else if(visited[v] == TRUE && v != parent){
              // If an adjacent is visited and not parent of current vertex, then there is a cycle.
               return TRUE;
            }
        }

    }
    return FALSE;
}
