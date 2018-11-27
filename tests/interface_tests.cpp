#include "undirected_graph.h"
#include "edges.h"
#include "doctest.h"

  TEST_CASE("Id de um grafo sem arestas"){
   CHECK_NOTHROW(Undirected u(10));
  }

TEST_CASE("Interface Base - Testes Basiscos"){
  Edges ed;

  for( int i=1; i<=5; i++ ){
    for( int j=1; j<=5; j++ ){
      if( i==j )continue;
      ed.insert(i, j);
    }
  }

  CHECK_NOTHROW(Undirected(5, ed));

  Undirected u(5, ed);

  CHECK(u.size() == 10);
  CHECK(u.order() == 5);

  for( int i=1; i<=5; i++ ){
    for( int j=1; j<=5; j++ ){
      if( i==j )continue;
      CHECK(u.has_edge(i, j));
    }
  }

  CHECK(u.complete());
  CHECK(u.regular());
}

TEST_CASE("Interface Base - Subgrafo"){

  Edges ed1;
  for( int i=1; i<=5; i++ ){
    for( int j=1; j<=5; j++ ){
      if( i==j )continue;
      ed1.insert(i, j);
    }
  }

  Edges ed2;
  ed2.insert(1, 2);
  ed2.insert(1, 3);
  ed2.insert(1, 4);
  ed2.insert(1, 5);

  Undirected u1(5, ed1);
  Undirected u2(5, ed2);

  CHECK(u1.subgraph(u2));
  CHECK(!u2.subgraph(u1));

  Edges ed3;
  ed3.insert(2, 3);
  ed3.insert(4, 3);

  Undirected u3(5, ed3);

  CHECK(!u2.subgraph(u3));
}

TEST_CASE("Interface Base - Distancias - 1"){
  Edges ed;
  ed.insert(1, 2, 1);
  ed.insert(1, 3, 1);
  ed.insert(1, 6, 100);
  ed.insert(2, 4, 1);
  ed.insert(4, 6, 1);
  ed.insert(3, 5, 2);
  ed.insert(5, 6, 2);

  Undirected u(6, ed);
  CHECK(u.find_distance(1, 2) == 1);
  CHECK(u.find_distance(1, 3) == 1);
  CHECK(u.find_distance(1, 4) == 2);
  CHECK(u.find_distance(1, 5) == 3);
  CHECK(u.find_distance(1, 6) == 3);
}

TEST_CASE("Interface Base - Distancias - 2"){
  Edges ed;
  ed.insert(1, 2, 1);
  ed.insert(1, 3, 100);
  ed.insert(1, 4, 100);
  ed.insert(1, 5, 100);

  ed.insert(2, 5, 1);
  ed.insert(5, 4, 1);
  ed.insert(4, 3, 1);
  ed.insert(3, 2, 1);

  Undirected u(5, ed);

  CHECK(u.find_distance(1, 2) == 1);
  CHECK(u.find_distance(1, 3) == 2);
  CHECK(u.find_distance(1, 5) == 2);
  CHECK(u.find_distance(1, 4) == 3);
}

TEST_CASE("Interface Base - Excecoes"){
  CHECK_THROWS(Undirected(10000));
  CHECK_THROWS(Undirected(-1));

  Undirected u(3);

  CHECK_THROWS(u.has_edge(-1, 1));
  CHECK_THROWS(u.has_edge(100000, 1));

  CHECK_THROWS(u.find_distance(-1));
}
