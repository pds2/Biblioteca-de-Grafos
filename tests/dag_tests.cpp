#include "dag.h"
#include "doctests.h"

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
  CHECK_THROWS(find_distance(-5, 20));
  CHECK(find_distance(3, 4) == 1);
}
