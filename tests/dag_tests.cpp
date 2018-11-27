#include "dag.h"
#include "doctest.h"

TEST_CASE("Teste_construtor dag"){
  CHECK_NOTHROW(DAG d(50));
}

TEST_CASE("Teste_destrutor dag"){
  DAG *d = new DAG(13);
  CHECK_NOTHROW(delete d);
}

TEST_CASE("Testando adicionar arestas"){
  DAG d(30);
  CHECK_NOTHROW(d.add_edge(1, 2, 4));
  CHECK_NOTHROW(d.add_edge(2, 3, 2));
  CHECK_NOTHROW(d.add_edge(5, 4, 3));
}

TEST_CASE("Arestas que não podem ser adicionadas"){
  DAG d(20);
  CHECK_THROWS(d.add_edge(-5, 15, 1));
  CHECK_THROWS(d.add_edge(3, 50, 3));
  CHECK_THROWS(d.add_edge(60, -50, 30));
}

TEST_CASE("Testando inserir aresta que gera ciclo"){
  DAG d(10);
  d.add_edge(3, 4, 1);
  d.add_edge(4, 6, 1);
  CHECK_THROWS(d.add_edge(6, 3, 1));
}

TEST_CASE("Testando find distance"){
  DAG d(10);
  d.add_edge(3, 4, 1);
  CHECK_THROWS(d.find_distance(-5, 20));
  CHECK(d.find_distance(3, 4) == 1);
}

TEST_CASE("DAG - Teste Basico"){
  Edges ed;

  ed.insert(1, 2);
  ed.insert(1, 3);
  ed.insert(2, 4);
  ed.insert(3, 4);

  CHECK_NOTHROW(DAG(4, ed));

  CHECK_NOTHROW(DAG d(4));

  DAG d(4);
  d.add_edge(1, 2);
  d.add_edge(1, 3);
  d.add_edge(2, 4);
  d.add_edge(3, 4);
  CHECK(d.has_cycle() == 0);
}
