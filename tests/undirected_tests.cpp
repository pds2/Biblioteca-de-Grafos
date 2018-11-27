#include "undirected_graph.h"
#include "edges.h"
#include "doctest.h"



TEST_CASE("TESTE - Construtor com vertices"){
    CHECK_NOTHROW(Undirected u(5));
}

TEST_CASE("TESTE - Construtor com vertices e arestas"){
  Edges ed;
  ed.insert(1, 2);
  ed.insert(1, 3);
  ed.insert(1, 4);
    CHECK_NOTHROW(Undirected u(5, ed));
}

TEST_CASE("TESTE - Destrutor"){
    Undirected *u = new Undirected(1);
    CHECK_NOTHROW(delete u);
}

TEST_CASE("TESTE - Adicionar aresta sem pesos"){
  Undirected ug(5);
  ug.add_edge(1, 1);
  ug.add_edge(1, 2);
  CHECK(ug.has_edge(1, 1) == DEFAULT_EDGE_WEIGHT);
  CHECK(ug.has_edge(1, 2) == DEFAULT_EDGE_WEIGHT);
  CHECK(ug.has_edge(2, 1) == DEFAULT_EDGE_WEIGHT);
  CHECK(ug.has_edge(3, 2) == 0);
  CHECK(ug.has_edge(2, 3) == 0);
}
TEST_CASE("TESTE - Adicionar aresta com pesos"){
  Undirected ug(5);
  ug.add_edge(1, 1, 1);
  ug.add_edge(1, 2, 9);
  ug.add_edge(3, 2, -3);
  CHECK(ug.has_edge(1, 1) == 1);
  CHECK(ug.has_edge(1, 2) == 9);
  CHECK(ug.has_edge(2, 1) == 9);
  CHECK(ug.has_edge(3, 2) == -3);
  CHECK(ug.has_edge(2, 3) == -3);
  CHECK(ug.has_edge(4, 2) == 0);
  CHECK(ug.has_edge(2, 4) == 0);
}
TEST_CASE("TESTE - Remover aresta"){
  Edges ed;
  ed.insert(1, 1);
  ed.insert(1, 2, 9);
  ed.insert(3, 2, -3);
  Undirected ug(5, ed);
  ug.remove_edge(1, 1);
  ug.remove_edge(1, 2);
  ug.remove_edge(2, 3);
  CHECK(ug.has_edge(1, 1) == 0);
  CHECK(ug.has_edge(1, 2) == 0);
  CHECK(ug.has_edge(2, 1) == 0);
  CHECK(ug.has_edge(3, 2) == 0);
  CHECK(ug.has_edge(2, 3) == 0);
  CHECK(ug.has_edge(4, 2) == 0);
  CHECK(ug.has_edge(2, 4) == 0);
}

TEST_CASE("Undirected - Kruskal"){
  Edges ed;
  ed.insert(1, 2, 1);
  ed.insert(3, 1, 1);
  ed.insert(1, 4, 1);
  ed.insert(5, 1, 1);

  ed.insert(2, 3, 100);
  ed.insert(2, 4, 100);
  ed.insert(2, 5, 100);

  ed.insert(3, 4, 100);
  ed.insert(3, 5, 100);

  ed.insert(4, 5, 100);

  Undirected u(5, ed);

  Tree *t = u.kruskal();
  t->set_root(1);

  CHECK(t->get_parent(2) == 1);
  CHECK(t->get_parent(3) == 1);
  CHECK(t->get_parent(4) == 1);
  CHECK(t->get_parent(5) == 1);

  CHECK(t->num_level() == 2);

}
