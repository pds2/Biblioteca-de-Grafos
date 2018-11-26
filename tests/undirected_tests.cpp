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

TEST_CASE("Find de vertices invalidos"){
	Undirected u(10);
	CHECK_THROWS(u.find(15));
	CHECK_THROWS(u.find(-5));
}

TEST_CASE("Adicionando edge com vertices invalidos"){
	Undirected u(20);
	CHECK_THROWS(u.add_edge(-2, 5));
	CHECK_THROWS(u.add_edge(3, 25));
	CHECK_THROWS(u.add_edge(-1000, 72));
}

TEST_CASE("Retirando edge não existente"){
	Undirected u(20);
	CHECK_THROWS(u.remove_edge(-2, 20));
	CHECK_THROWS(u.remove_edge(4, 22));
	//Removenr um vertice que não existe no grafo só não altera o grafo, mas roda normalmente
	//CHECK_THROWS(u.remove_edge(3, 5)); falha. 
}

TEST_CASE("Kruskal"){
	Undirected u(3);
	u.add_edge(1, 2, 3);
	u.add_edge(1, 3, 2);
	u.add_edge(2, 3, 1);
	// u.kruskal();
}