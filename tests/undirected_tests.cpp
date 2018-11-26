#include "undirected_graph.h"
#include "doctest.h"

TEST_CASE("Union de um grafo não dirigido"){
	Undirected u(5);
	u.add_edge(1, 2);
	u.add_edge(1, 3);
	CHECK(u.find(3) == u.find(2));
	CHECK(u.find(2) == u.find(1));  
}
TEST_CASE("Union de um grafo não dirigido direção contrária"){
	Undirected u(5);
	u.add_edge(2, 1);
	u.add_edge(3, 1);
	CHECK(u.find(3) == u.find(2));
	CHECK(u.find(2) == u.find(1));
}